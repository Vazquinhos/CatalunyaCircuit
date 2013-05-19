#include "assimpLog.h"
#include <QDebug>

AssimpLog::AssimpLog()
{
}

AssimpLog::~AssimpLog()
{
}


// Write womethink using your own functionality
void AssimpLog::write(const char* message)
{
    qDebug() << message;
}

