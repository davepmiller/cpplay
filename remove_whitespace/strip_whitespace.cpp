#include <iostream>
#include <string>
#include <algorithm>
#include <functional>


std::function<bool( char ch )> is_whitespace =
        []( char ch ){ return std::isspace( ch ); };


std::string get_input(){
    std::string input;
    std::getline( std::cin, input );

    return input;
}


std::string remove_whitespace( std::string input ){
    input.erase( std::remove_if( input.begin(), input.end(), is_whitespace ),
                 input.end() );

    return input;
}


int main(){
    std::cout << remove_whitespace( get_input() ) << std::endl;

    return 0;
}
