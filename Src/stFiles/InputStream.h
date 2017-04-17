#pragma once

#include <stUtils/NonCopyable.h>
#include <fstream>

namespace stContainers {
class String;
}

namespace stFiles {

class InputStream : stUtils::NonCopyable
{
public:
    static bool ReadFileToString( stContainers::String& outString, const char* pszFilePath );

private:
    bool Open( const char* pszFilePath );
    bool ReadFile( stContainers::String& outString );

    bool IsOpen() const { return _stream.is_open(); }

private:
    std::fstream _stream;
};

} //stFiles
