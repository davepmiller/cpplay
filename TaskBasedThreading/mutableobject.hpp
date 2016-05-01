#ifndef MUTABLEOBJECT_HPP
#define MUTABLEOBJECT_HPP

#include <string>
#include <atomic>
#include <mutex>

using namespace std;

class MutableObject
{

public:

    MutableObject();

    void setMutableString( string );

    string getMutableString();

    void repeatMutate();

    static bool _run;

private:

    bool _flag;

    string _mutableString;

    mutex _stringMutex;

};

#endif // MUTABLEOBJECT_HPP
