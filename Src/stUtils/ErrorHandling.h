#include "stUtils/Log.h"

#define ST_ExitWithError ST_ExitLabel

#define ST_ReturnBool( msg ) return true; ST_ExitLabel: stUtils::Log::Error( msg ); return false;

#define ST_Ensure( x ) do{ if( !( x ) ){ stUtils::Log::Error( "Failed ensure at line __LINE__ " ); goto ST_ExitLabel; } }while( 0 )

