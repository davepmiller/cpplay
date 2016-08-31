#include <iostream>
#include <vector>
#include <algorithm>


using std::string;
using std::cout;
using std::endl;


bool isAPalinDrome( const string & stringToCheck )
{
    return stringToCheck ==
            string{ stringToCheck.rbegin(), stringToCheck.rend() };
}


void printPalindrome( int index, const string & stringToPrint )
{
    cout << index << ": " << stringToPrint << endl;
}


bool checkForNextPermutation( string & str )
{
    return next_permutation( str.begin(), str.end() );
}


void findPalindromes( string stringToCheck )
{
    auto palindromeNumber = 1;

    do
    {
       if( isAPalinDrome( stringToCheck ) )
       {
           printPalindrome( palindromeNumber++, stringToCheck );
       }
    }
    while( checkForNextPermutation( stringToCheck) );

    cout << endl;
}


int main( int argc, char * argv[] )
{
    cout << endl;

    for( auto index = 1; index < argc; ++index )
    {
        cout << argv[ index ] << ":" << endl;

        findPalindromes( argv[ index ] );
    }
}
