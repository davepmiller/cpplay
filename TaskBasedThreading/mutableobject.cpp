#include "mutableobject.hpp"

#include <iostream>
#include <thread>

using namespace std;

bool MutableObject::_run = true;

MutableObject::MutableObject()
    :
    _mutableString( "mutableString" )
{}

void MutableObject::setMutableString( string input )
{
    lock_guard< mutex > l{ _stringMutex };

    _mutableString = input;
}

string MutableObject::getMutableString()
{
    lock_guard< mutex > l{ _stringMutex };

    return _mutableString;
}

void MutableObject::repeatMutate()
{
    while( MutableObject::_run )
    {
        _flag = !_flag;

        lock_guard< mutex > l{ _stringMutex };

        if( _flag )
            _mutableString = "salmon";
        else
            _mutableString = "trout";
    }
}
