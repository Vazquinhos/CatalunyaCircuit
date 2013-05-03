#ifndef ASSIMPLOG_H
#define ASSIMPLOG_H

#include <assimp/LogStream.hpp>

class AssimpLog :
        public Assimp::LogStream
{
public:
    AssimpLog();
    ~AssimpLog();
    void write(const char* message);
};

#endif // ASSIMPLOG_H
