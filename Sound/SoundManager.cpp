#include <stdio.h>
#include <AL/alc.h>
#include <AL/alut.h>
#include "Utils/point3D.h"
#include "SoundManager.h"

SoundManager * SoundManager::mSoundManager=NULL;

SoundManager::SoundManager()
: mSoundON(true)
, mPause(false)
{
	mSoundON = _initAL();
}

SoundManager::~SoundManager()
{}

SoundManager* SoundManager::GetInstance()
{
	if (mSoundManager==NULL)
	{
		mSoundManager = new SoundManager();
	}
	return mSoundManager;
}

void SoundManager::CleanUP()
{
	if( mSoundManager != NULL )
	{
		_finalizeAL();
		
		delete mSoundManager;
		mSoundManager = NULL;
	}	
}

//-----------GENERAL FUNCTIONS---------------------
bool SoundManager::LoadSounds(const std::string& xmlSoundsFile)
{
	// read the xml sounds file
	return xmlParseFile(xmlSoundsFile);
}


void SoundManager::SetGain(float gain)
{
	alListenerf(AL_GAIN,gain);
}

float SoundManager::GetGain()
{
	float gain;
	alGetListenerf(AL_GAIN,&gain);
	return gain;
}


void SoundManager::Reset()
{
	Stop();
	_clear();
}

void SoundManager::Pause()
{
	ALint state;
	std::vector<InfoSource>::iterator it;
	mPause = !mPause;

	for( it = mSources.begin(); it != mSources.end(); ++it )
	{
		alGetSourcei( (*it).source, AL_SOURCE_STATE, &state);
		if (state == AL_PLAYING && mPause)
		{
			alSourcePause((*it).source);
		}
		else if (state == AL_PAUSED && !mPause)
		{
			alSourcePlay((*it).source);
		}
	}
}

void SoundManager::Stop()
{
	ALint state;
	std::vector<InfoSource>::iterator it;

	for( it = mSources.begin(); it != mSources.end(); ++it )
	{
		alGetSourcei((*it).source,AL_SOURCE_STATE, &state);
		if (state == AL_PLAYING || state == AL_PAUSED)
		{
			alSourceStop((*it).source);
		}
	}
}

//parsers the xml sound file
void SoundManager::onStartElement( const std::string &elem, MKeyValue &atts )
{
	bool baction = false;
	bool bfile = false;
	
	std::string action;
	std::string file;

	if (elem=="Sound")
	{
		//Process a Sound
		if (atts["action"]!="")
		{
			action  = atts["action"];
			baction = true;
		}
		if (atts["path"]!="")
		{
			file  = atts["path"];
			bfile = true;
		}
		if (bfile && baction)
		{
			//Buscamos si tenemos registrada la acción "action"
			std::map<Action, IdBuffer>::iterator it = mBuffers.find( action );
			if( it == mBuffers.end() )
			{
				//Si aún no la hemos registrado, la añadimos:
				std::map<SoundFile,IdBuffer>::iterator it = mFilesLoaded.find( file );
				if( it != mFilesLoaded.end() )
				{
					//Ya hemos cargado el fichero de sonido:
					IdBuffer idBuffer = (*it).second;
					mBuffers.insert(std::pair<Action, IdBuffer>(action, idBuffer) );
				}
				else
				{
					IdBuffer idBuffer;
					if( _loadSound(file, idBuffer) )
					{
						mFilesLoaded.insert(std::pair<SoundFile, IdBuffer>(file, idBuffer) );
						mBuffers.insert(std::pair<Action, IdBuffer>(action, idBuffer) );
					}
				}

			}//End if( (it == mBuffers.end() )

		}//End if (elem=="sound")
		
	}//End if (elem=="sound")

}


//---------ACTION FUNCTIONS-------------------------------
bool SoundManager::PlayAction( const std::string& action, Point3D position )
{
	if (mSoundON)
	{	
		std::map<Action, IdBuffer>::iterator it = mBuffers.find(action);
		if (it==mBuffers.end())
		{
			//printLOG("Action " + action + " not found");
            //qDebug() << "Action no encontrada";
			return false;
		}
		IdBuffer idBuffer = (*it).second;
		int index;
        ALfloat ListenerPos[3] = { position.getX(), position.getY(), position.getZ() };
		ALfloat ListenerVel[3] = { 0.0, 0.0, 0.0 };
		
		index = _getSource(false);
	
		if (index==-1)
			return false;
	
		// Get Listener position and velocity, for maxium gain (2D sound)
		alGetListenerfv (AL_VELOCITY,ListenerVel);
		
		alSourcei (mSources[index].source, AL_BUFFER, idBuffer);
		alSourcef (mSources[index].source, AL_PITCH, 1.0);
		alSourcef (mSources[index].source, AL_GAIN, 1.0);
		alSourcefv(mSources[index].source, AL_POSITION, ListenerPos);
		alSourcefv(mSources[index].source, AL_VELOCITY, ListenerVel);
		alSourcei (mSources[index].source, AL_LOOPING, AL_FALSE);
	
		alSourcePlay(mSources[index].source);
	}
	return true;
}

bool SoundManager::PlayAction(const std::string& action)
{
	if (mSoundON)
	{	
		std::map<Action, IdBuffer>::iterator it = mBuffers.find(action);
		if (it==mBuffers.end())
		{
			//printLOG("Action " + action + " not found");
			return false;
		}
		IdBuffer idBuffer = (*it).second;
		int index;
		ALfloat vector[3] = { 0.0, 0.0, 0.0 };
		
		
		index = _getSource(false);
	
		if (index==-1)
			return false;
	
		alSourcei (mSources[index].source, AL_BUFFER, idBuffer);
		alSourcei (mSources[index].source, AL_SOURCE_RELATIVE, AL_TRUE);
		alSourcef (mSources[index].source, AL_PITCH, 1.0);
		alSourcef (mSources[index].source, AL_GAIN, 1.0);
		alSourcefv(mSources[index].source, AL_POSITION, vector);
		alSourcefv(mSources[index].source, AL_VELOCITY, vector);
		alSourcefv(mSources[index].source, AL_DIRECTION, vector);
		alSourcei (mSources[index].source, AL_LOOPING, AL_FALSE);
	
		alSourcePlay(mSources[index].source);
	}
	return true;
}


//-----SOURCE FUNCTIONS----------------------------
int SoundManager::CreateSource()
{
	return _getSource(true);
}

bool SoundManager::DeleteSource(int source)
{
	if (source >= 0 && (unsigned int)source<mSources.size())
	{
		StopSource(source);
		mSources[source].reserved = false;
	}
	return true;
}

bool SoundManager::PlayRelativeSource(int source, const std::string& action, bool loop)
{
	if (mSoundON)
	{
		if (source >= 0 && (unsigned int)source<mSources.size() && mSources[source].reserved)
		{
			ALboolean alloop;
	
			if (loop)
				alloop = AL_TRUE;
			else
				alloop = AL_FALSE;
			
			StopSource(source);
	
			if (mBuffers.find(action)==mBuffers.end())
			{
				//printLOG("Action " + action + " not found");

				return false;
			}
	
			ALfloat vector[3] = { 0.0, 0.0, 0.0 };
			alSourcei (mSources[source].source, AL_BUFFER, mBuffers[action]);
			alSourcei (mSources[source].source, AL_SOURCE_RELATIVE, AL_TRUE);
			alSourcef (mSources[source].source, AL_PITCH, 1.0);
			alSourcef (mSources[source].source, AL_GAIN, 1.0);
			alSourcefv(mSources[source].source, AL_POSITION, vector);
			alSourcefv(mSources[source].source, AL_VELOCITY, vector);
			alSourcefv(mSources[source].source, AL_DIRECTION, vector);
			alSourcei (mSources[source].source, AL_LOOPING, alloop);
			alSourcePlay(mSources[source].source);
	
			return true;
		}	
		else
		{
			//printLOG("Can't play source. Invalid source " + source );
			return false;
		}
	}
	return true;
}

bool SoundManager::PlaySource(int source, const std::string& action, bool loop)
{
	if (mSoundON)
	{
		if (source >= 0 && (unsigned int)source<mSources.size() && mSources[source].reserved)
		{
			ALboolean alloop;
	
			if (loop)
				alloop = AL_TRUE;
			else
				alloop = AL_FALSE;
			
			StopSource(source);
	
			if (mBuffers.find(action)==mBuffers.end())
			{
				//printLOG("Action " + action + " not found");
				return false;
			}
	
			alSourcei (mSources[source].source, AL_BUFFER, mBuffers[action]);
			alSourcef (mSources[source].source, AL_PITCH, 1.0);
			alSourcef (mSources[source].source, AL_GAIN, 1.0);
			alSourcei (mSources[source].source, AL_LOOPING, alloop);
	
			alSourcePlay(mSources[source].source);
	
			return true;
		}	
		else
		{
			//printLOG("Can't play source. Invalid source " + source );
			return false;
		}
	}
	return true;
}


bool SoundManager::PauseSource(int source)
{
	if (source >= 0 && (unsigned int)source<mSources.size() && mSources[source].reserved)
	{
		ALint state;
		
		alGetSourcei(mSources[source].source,AL_SOURCE_STATE, &state);
		if (state == AL_PLAYING)
		{
			alSourcePause(mSources[source].source);
		}
		else if (state == AL_PAUSED)
		{
			alSourcePlay(mSources[source].source);
		}		
		return true;
	}
	else
	{
		//printLOG("Can't pause source. Invalid source " + source );
		return false;
	}
}


bool SoundManager::StopSource(int source)
{
	if (source >= 0 && (unsigned int)source<mSources.size() && mSources[source].reserved)
	{
		ALint state;
		
		alGetSourcei(mSources[source].source,AL_SOURCE_STATE, &state);
		if (state == AL_PLAYING || state== AL_PAUSED)
		{
			alSourceStop(mSources[source].source);
		}
		return true;
	}
	else
	{
		//printLOG("Can't stop source. Invalid source " + source );
		return false;
	}
	
}


bool SoundManager::SetSourcePosition( int source, const Point3D& inPosition )
{
	if (source >= 0 && (unsigned int)source<mSources.size() && mSources[source].reserved)
	{
        ALfloat pos[3] = { inPosition.getX(), inPosition.getY(), inPosition.getZ() };
        alSourcefv(mSources[source].source, AL_POSITION, pos);
		return true;
	}
	else
	{
		//printLOG("Can't set source position. Invalid source " + source );
		return false;
	}
}

bool SoundManager::GetSourcePosition( int source, Point3D& outPosition )
{
	if (source >= 0 && (unsigned int)source<mSources.size() && mSources[source].reserved)
	{
        ALfloat pos[3] = { outPosition.getX(), outPosition.getY(), outPosition.getZ() };
        alSourcefv(mSources[source].source, AL_POSITION, pos);
		return true;
	}
	else
	{
		//printLOG("Can't get source position. Invalid source " + source );
		return false;
	}
}

bool SoundManager::SetSourceVelocity( int source, const Point3D& inVelocity )
{
	if (source >= 0 && (unsigned int)source<mSources.size() && mSources[source].reserved)
	{
        ALfloat pos[3] = { inVelocity.getX(), inVelocity.getY(), inVelocity.getZ() };
        alSourcefv(mSources[source].source, AL_POSITION, pos);
		return true;
	}
	else
	{
		//printLOG("Can't set source velocity. Invalid source " + source );
		return false;
	}
}


bool SoundManager::GetSourceVelocity( int source, Point3D& outVelocity )
{
	if (source >= 0 && (unsigned int)source<mSources.size() && mSources[source].reserved)
	{
        ALfloat pos[3] = { outVelocity.getX(), outVelocity.getY(), outVelocity.getZ() };
        alSourcefv(mSources[source].source, AL_POSITION, pos);
		return true;
	}
	else
	{
		//printLOG("Can't get source velocity. Invalid source " + source );
		return false;
	}	
}

bool SoundManager::SetSourceGain(int source, float gain)
{
	if (source >= 0 && (unsigned int)source<mSources.size() && mSources[source].reserved)
	{
		alSourcef(mSources[source].source, AL_GAIN, gain);
		return true;
	}
	else
	{
		//printLOG("Can't set source gain. Invalid source " + source );
		return false;
	}
}


bool SoundManager::GetSourceGain(int source, float& gain)
{
	if (source >= 0 && (unsigned int)source<mSources.size() && mSources[source].reserved)
	{
		alGetSourcef(mSources[source].source, AL_GAIN, &gain);
		return true;
	}
	else
	{
		//printLOG("Can't get source gain. Invalid source " + source );
		return false;
	}
}

void SoundManager::SetListenerPosition( const Point3D& inPosition )
{
    ALfloat pos[3] = { inPosition.getX(), inPosition.getY(), inPosition.getZ() };
    alListenerfv(AL_POSITION, pos);
}

void SoundManager::GetListenerPosition( Point3D& outPosition )
{
    ALfloat pos[3] = { outPosition.getX(), outPosition.getY(), outPosition.getZ()};
    alGetListenerfv(AL_POSITION, pos);
}

void SoundManager::SetListenerVelocity( const Point3D& inVelocity )
{
    ALfloat pos[3] = { inVelocity.getX(), inVelocity.getY(), inVelocity.getZ()};
    alListenerfv(AL_VELOCITY, pos);
}

void SoundManager::GetListenerVelocity( Point3D& outVelocity )
{
    ALfloat pos[3] = { outVelocity.getX(), outVelocity.getY(), outVelocity.getZ()};
    alGetListenerfv(AL_VELOCITY, pos);
}


void SoundManager::SetListenerOrientation( const Point3D& inAt, const Point3D& inUp )
{
	float ori[6];
    ori[0] = inAt.getX();
    ori[1] = inAt.getY();
    ori[2] = inAt.getZ();
    ori[3] = inUp.getX();
    ori[4] = inUp.getY();
    ori[5] = inUp.getZ();
	alListenerfv(AL_ORIENTATION, ori);	
}

void SoundManager::GetListenerOrientation( Point3D& outAt, Point3D& outUp )
{
	float ori[6];
	alGetListenerfv(AL_ORIENTATION, ori);	
    outAt.setCoordinates(ori[0], ori[1], ori[2]);
    outUp.setCoordinates(ori[3], ori[4], ori[5]);
}


//---------------PRIVATE FUNCTIONS-------------------------------------------
bool SoundManager::_initAL()
{
	ALenum error;
	ALCdevice* pDevice;
	ALCcontext* pContext;

	// Get handle to default device.
	pDevice = alcOpenDevice(NULL);

	// Get the device specifier.
	//const ALCubyte* deviceSpecifier = alcGetString(pDevice, ALC_DEVICE_SPECIFIER);

	// Create audio context.
	pContext = alcCreateContext(pDevice, NULL);

	// Set active context.
	alcMakeContextCurrent(pContext);

	// Check for an error.
	if ((error=alcGetError(pDevice)) != ALC_NO_ERROR)
	{
		//printLOG("Can't create openAL contextn (" + _getALErrorString(error) + ")");
		return false;
	}
	return true;
}

void SoundManager::_finalizeAL()
{
	_clear();
	
	ALCcontext* pCurContext;
	ALCdevice* pCurDevice;

	// Get the current context.
	pCurContext = alcGetCurrentContext();

	// Get the device used by that context.
	pCurDevice = alcGetContextsDevice(pCurContext);

	// Reset the current context to NULL.
	alcMakeContextCurrent(NULL);

	// Release the context and the device.
	alcDestroyContext(pCurContext);
	alcCloseDevice(pCurDevice);
}

bool SoundManager::_loadSound(const std::string& file, IdBuffer& buffer)
{
	// Variables to load into.
	FILE *fd;
	ALenum format;
	ALenum error;
	ALsizei size;
	ALvoid* data;
	ALsizei freq;
	ALboolean loop;

	
	// Load wav data into buffers.
	alGenBuffers(1, &buffer);

	if((error=alGetError()) != AL_NO_ERROR)
	{	
		alDeleteBuffers(1,&buffer);
		//printLOG("Error: Can't create openAL Buffer (" + _getALErrorString(error)  + ")");		
		return false;	
	}

	// Check if the file exists
	if ((fd=fopen(file.c_str(),"r"))==NULL)
	{
		alDeleteBuffers(1,&buffer);
		//printLOG("Error: Can't open file " + action.getFile());		
		return false;
	}
	else
	{
		fclose(fd);
	}

	alutLoadWAVFile((ALbyte*)file.c_str(), &format, &data, &size, &freq, &loop);
	alBufferData(buffer, format, data, size, freq);
	alutUnloadWAV(format, data, size, freq);
	if ((error=alGetError()) != AL_NO_ERROR)
	{		
		alDeleteBuffers(1,&buffer);
		//printLOG("Error: Can't load sound file " + action.getFile() + " (" + _getALErrorString(error)  + ")");		
		return false;
	}		
	return true;
}

void SoundManager::_clear()
{
	// Delete AL objets
	ALuint aux;	
	std::map<Action, IdBuffer>::iterator itBuffer;
	for( itBuffer = mBuffers.begin(); itBuffer != mBuffers.end(); ++itBuffer )
	{
		aux = (*itBuffer).second;
		alDeleteBuffers (1,&aux);
	}
	
	std::vector<InfoSource>::iterator itSource;
	for( itSource = mSources.begin(); itSource != mSources.end(); ++itSource )
	{
		aux = (*itSource).source;
		alDeleteSources (1,&aux);
	}
	
	mBuffers.clear();
	mSources.clear();
	mFilesLoaded.clear();
}

int SoundManager::_getSource(bool reserved)
{
	// Find a unused source
	int i=0;
	bool found=false;
	ALint state;
	ALenum error;
	
	for( unsigned int i=0; i < mSources.size(); i++)
	{
		if (!mSources[i].reserved)
		{
			// Check if it is being used
			alGetSourcei(mSources[i].source,AL_SOURCE_STATE, &state);
			if (state != AL_PLAYING && state != AL_PAUSED)
			{
				mSources[i].reserved = reserved;
				return i;
			}			
		}
	}
		
	InfoSource info;
	alGenSources(1,&info.source);
	if ((error=alGetError())!=AL_NO_ERROR)
	{
		//printLOG("Can't create source (" + _getALErrorString(error) + ")");
		i=-1;
	}
	else
	{
		info.reserved=reserved;
		mSources.push_back(info);
		i = mSources.size() - 1;			
	}
	
	return i;
}

std::string SoundManager::_getALErrorString(ALenum err)
{
    switch(err)
    {
        case AL_NO_ERROR:
            return std::string("AL_NO_ERROR");
        break;

        case AL_INVALID_NAME:
            return std::string("AL_INVALID_NAME");
        break;

        case AL_INVALID_ENUM:
            return std::string("AL_INVALID_ENUM");
        break;

        case AL_INVALID_VALUE:
            return std::string("AL_INVALID_VALUE");
        break;

        case AL_INVALID_OPERATION:
            return std::string("AL_INVALID_OPERATION");
        break;

        case AL_OUT_OF_MEMORY:
            return std::string("AL_OUT_OF_MEMORY");
        break;
    };
}
