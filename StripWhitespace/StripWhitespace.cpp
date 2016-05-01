#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string getInput( string input )
{
    getline( cin, input );

    return input;
}

string removeWhitespace( string input )
{
    input.erase( remove_if( input.begin(),
                            input.end(),
                            []( char ch ){ return isspace( ch ); } ),
                 input.end() );

    return input;
}

int main()
{
    cout << removeWhitespace( getInput( {} ) ) << endl;

    return 0;
}
