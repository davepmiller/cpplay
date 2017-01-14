#include <iostream>
#include <thread>
#include <memory>
#include <future>
#include <atomic>

#include <mutableobject.hpp>

using namespace std;

unique_ptr< MutableObject > objectOne;
unique_ptr< MutableObject > objectTwo;

void separateThreadTask()
{
    while( MutableObject::_run )
    {
        objectOne->setMutableString( "sturgeon" );
        objectTwo->setMutableString( "sturgeon" );
    }
}

void printTask()
{
    while( MutableObject::_run )
    {
        cout << "Object One: " << objectOne->getMutableString() << endl;
        cout << "Object Two: " << objectTwo->getMutableString() << endl;
    }
}

int main()
{
    MutableObject::_run = true;

    objectOne = unique_ptr< MutableObject >( new MutableObject() );
    objectTwo = unique_ptr< MutableObject >( new MutableObject() );

    auto futureOne = async( launch::async, &MutableObject::repeatMutate, objectOne.get() );
    auto futureTwo = async( launch::async, &MutableObject::repeatMutate, objectTwo.get() );
    auto futureThree = async( launch::async, separateThreadTask );

    auto futurePrint = async( launch::async, printTask );

    for( auto i = 0; i < 1000000; ++i )
    {
        objectOne->setMutableString( "bass" );
        objectTwo->setMutableString( "bass" );
    }

    MutableObject::_run = false;

    futureOne.get();
    futureTwo.get();
    futureThree.get();
    futurePrint.get();

    return 0;
}

