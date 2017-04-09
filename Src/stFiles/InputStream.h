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
    bool Open( const char* pszFilePath );
    bool ReadFile( stContainers::String& outString );

private:
    bool IsOpen() const { return _stream.is_open(); }

private:
    std::fstream _stream;
};

} //stFiles
