#pragma once

#include "stTypes/Types.h"
#include "stUtils/Assertions.h"
#include "stUtils/NonCopyable.h"

#include <vector>

namespace stContainers {

template< typename T, unsigned int N=20 >
class RingBuffer : stUtils::NonCopyable
{
public:
    void PushBack( T value )
    {
        ST_StaticAssert( N > 0 );
        
        ST_Assert( _currentIndex >= 0 && _currentIndex < N );
        _buffer[ _currentIndex ] = value;

        ++_currentIndex;
        if( _currentIndex >= N )
        {
            _currentIndex = 0;
        }

        if( _size < N )
        {
            ++_size;
        }
    }

    int Size() const
    {
        return _size;
    }

    const T& operator[]( const int index ) const
    {
        ST_Assert( index >= 0 && index < _size );
        return _buffer[ index ];
    }

    T& operator[]( const int index )
    {
        ST_Assert( index >= 0 && index < _size );
        return buffer[ index ];
    }

public:
    class ConstIterator
    {
    public:
        ConstIterator( const RingBuffer& buffer, const int index )
        {
            _pElement = &buffer[ 0 ] + index;
        }

        const T& operator*() const
        {
            return *_pElement;
        }

        ConstIterator& operator++()
        {
            ++_pElement;
            return *this;
        }

        bool operator!=( const ConstIterator& other )
        {
            return _pElement != other._pElement;
        }

    private:
        const T* _pElement{ ST_NULL };
    };

public:
    ConstIterator begin() const
    {
        return ConstIterator( *this, 0 );
    }

    ConstIterator end() const
    {
        return ConstIterator( *this, _size );
    }


private:
    T _buffer[ N ];
    int _currentIndex{ 0 };
    int _size{ 0 };
};

} //stContainers
