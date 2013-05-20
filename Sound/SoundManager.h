#ifndef __SOUNDMANAGER_H
#define __SOUNDMANAGER_H

#include <string>
#include <map>
#include <vector>
#include "Utils/point3D.h"
#include <AL/al.h>
#include "Utils/XMLParser.h"


///-----------  DEFINICION DE NUEVOS TIPOS ------------------//
	typedef struct
	{
		ALuint	source;
		bool	reserved;
	}InfoSource;
	
	typedef std::string SoundFile;
	typedef std::string Action;
	typedef ALuint IdBuffer;
//----------------------------------------------------------//


class SoundManager: public CXMLParser
{
	public:		

		static SoundManager*	GetInstance		( void );
		void					CleanUP			( void );

		//-----------GENERAL FUNCTIONS---------------------
		//[sp] Cargar
		bool	LoadSounds	( const std::string& xmlSoundsFile );
		void	Reset		( void );
		void	Pause		( void );
		void	Stop		( void );
		void	SoundOn		( void ) {mSoundON=true;}
		void	SoundOff	( void ) {mSoundON=false;}
		void	SetGain		( float gain );
		float	GetGain		( void );
        

		//---------ACTION FUNCTIONS-------------------------------
		bool	PlayAction	( const std::string& action );
        bool	PlayAction	( const std::string& action, Point3D position );
		
	
		//-----SOURCE FUNCTIONS----------------------------
		int		CreateSource		( void );
		bool	DeleteSource		( int source );
        bool	PlaySource			( int source, const std::string& action, bool loop );
		bool	PlayRelativeSource	( int source, const std::string& action, bool loop );
		bool	PauseSource			( int source );
		bool	StopSource			( int source );
		bool	SetSourceGain		( int source, float inGain );
		bool	GetSourceGain		( int source, float& outGain );
        bool	SetSourcePosition	( int source, const Point3D& inPosition );
        bool	GetSourcePosition	( int source, Point3D& outPosition );
        bool	SetSourceVelocity	( int source, const Point3D& inVelocity );
        bool	GetSourceVelocity	( int source, Point3D& outVelocity );
		

		//-----LISTENER FUNCTIONS-------------------------
        void	SetListenerPosition		( const Point3D& inPosition );
        void	GetListenerPosition		( Point3D& outPosition );
        void	SetListenerVelocity		( const Point3D& inVelocity );
        void	GetListenerVelocity		( Point3D& outVelocity );
        void	SetListenerOrientation	( const Point3D& inAt, const Point3D& inUp );
        void	GetListenerOrientation	( Point3D& outAt, Point3D& outUp );
		
		
	private:
		bool		mSoundON;
		bool		mPause;
		
		std::map<Action, IdBuffer>		mBuffers;
		std::map<SoundFile,IdBuffer>	mFilesLoaded;
		std::vector<InfoSource>			mSources;
		

		static SoundManager * mSoundManager;
		
	private:	
		///Private constructor.
		SoundManager();
		///Private destructor. Some older compilers (like MSVC 6) may complain about this.
		~SoundManager();
		///Private unimplemented copy constructor to prevent copies.
		SoundManager(const SoundManager&);
		///Private unimplemented assignment operator to prevent assignment.
		SoundManager& operator=(const SoundManager&);

		void			onStartElement		( const std::string &elem, MKeyValue &atts );
		bool			_initAL				( void );
		void			_finalizeAL			( void );
		bool			_loadSound			( const std::string& file, IdBuffer& buffer );
		void			_clear				( void );
		int				_getSource			( bool reserved=false );
		std::string		_getALErrorString	(ALenum err);
};

#endif //__SOUNDMANAGER_H
