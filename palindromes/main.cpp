#include <iostream>
#include <algorithm>


using std::string;
using std::cout;
using std::endl;


bool is_a_palindrome( const string & stringToCheck ){
    return stringToCheck ==
            string{ stringToCheck.rbegin(), stringToCheck.rend() };
}


void print_palindrome( int index, const string & stringToPrint ){
    cout << index << ": " << stringToPrint << endl;
}


bool check_for_next_permutation( string & str ){
    return next_permutation( str.begin(), str.end() );
}


void find_palindromes( string stringToCheck ){
    auto palindromeNumber = 1;

    do{
       if( is_a_palindrome( stringToCheck ) )
           print_palindrome( palindromeNumber++, stringToCheck );
    }
    while( check_for_next_permutation( stringToCheck) );

    cout << endl;
}


int main( int argc, char * argv[] ){
    cout << endl;

    for( auto index = 1; index < argc; ++index ){
        cout << argv[ index ] << ":" << endl;
        find_palindromes( argv[ index ] );
    }
}
