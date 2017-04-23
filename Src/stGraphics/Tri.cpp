#include "Tri.h"

#include "Material.h"
#include "stUtils/ErrorHandling.h"

namespace stGraphics {

Tri::Tri( const stMaths::Vec3& v1, const stMaths::Vec3& v2, const stMaths::Vec3& v3 ) :
    _verts{ v1, v2, v3 }
{
    GLuint vbo{ 0 };
    glGenBuffers( 1, &vbo );
    glBindBuffer( GL_ARRAY_BUFFER, vbo );
    glBufferData( GL_ARRAY_BUFFER, sizeof( _verts ), _verts, GL_STATIC_DRAW );

    glGenVertexArrays( 1, &_vao );
    glBindVertexArray( _vao );
    glEnableVertexAttribArray( 0 );
    glBindBuffer( GL_ARRAY_BUFFER, vbo );
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, NULL );
}

void Tri::Render( const Material& material )
{
    ST_Ensure( material.IsLoaded() );

    glUseProgram( material.GetHandle() );
    glBindVertexArray( _vao );
    glDrawArrays( GL_TRIANGLES, 0, 3 );

    ST_Return( ( "Tri::Render() - failed!" ) );
}

} //stGraphics
