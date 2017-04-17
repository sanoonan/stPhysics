#include "InputStream.h"

#include "stContainers/String.h"
#include "stUtils/ErrorHandling.h"

namespace stFiles {

bool InputStream::ReadFileToString( stContainers::String& outString, const char* pszFilePath )
{
    InputStream iStream;
    ST_Ensure( pszFilePath );
    ST_Ensure( iStream.Open( pszFilePath ) );
    ST_Ensure( iStream.ReadFile( outString ) );

    ST_ReturnBool( ( "InputStream::ReadFileToString() - failed!" ) );
}

bool InputStream::Open( const char* pszFilePath )
{
    ST_Ensure( pszFilePath );
    ST_Ensure( !IsOpen() );

    _stream.open( pszFilePath );

    ST_Ensure( !_stream.fail() );

    ST_ReturnBool( ( "InputStreamImpl::Open() - failed to open [ ", pszFilePath, " ]!" ) );
}

bool InputStream::ReadFile( stContainers::String& outString )
{
    char szLine[ 1024 ];

    ST_Ensure( IsOpen() );

    while( !_stream.eof() )
    {
        szLine[ 0 ] = 0;
        _stream.getline( szLine, 1024 );

        ST_Ensure( !_stream.fail() );

        outString.Append( &szLine[ 0 ] ).Append( "\n" );
    }

    ST_ReturnBool( ( "InputStreamImpl::ReadFile() - failed!" ) );
}

} //stFiles
