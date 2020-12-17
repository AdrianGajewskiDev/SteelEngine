#include "FileLoader.h"

std::string FileLoader::READFROMTXT(const std::string& path)
{
    std::ifstream stream;

    std::stringstream txt;

    stream.open(path);

    if (stream.is_open())
    {
        txt << stream.rdbuf();
    }

    stream.close();
    
    return txt.str();
}
