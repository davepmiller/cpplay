#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isAPalinDrome( string stringToCheck )
{
    return stringToCheck ==
            string{ stringToCheck.rbegin(), stringToCheck.rend() };
}

void findPalindromes( string stringToCheck )
{
    do
    {
       if( isAPalinDrome( stringToCheck ) )
       {
           cout << "palindrome: " << stringToCheck << endl;
       }
    }
    while( next_permutation( stringToCheck.begin(), stringToCheck.end() ) );

    cout << endl;
}

int main( int argc, char * argv[] )
{
    for( auto index = 1; index < argc; ++index )
    {
        findPalindromes( argv[ index ] );
    }
}
