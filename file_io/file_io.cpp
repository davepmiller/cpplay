#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


std::string get_price( std::string inputLine ) {
    auto position = inputLine.find( "$" );

    return position <= inputLine.size() ?
                inputLine.substr( position ) : std::string{};
}


std::string get_barcode( std::string inputLine ) {
    auto position = inputLine.find( '$' );
    position -= 1;

    std::string barCode;
    while( std::isspace( inputLine[position] ) ) {
        --position;
    }

    while( ! std::isspace( inputLine[position] ) ) {
        barCode.insert( barCode.begin(), inputLine[position--] );
    }

    return barCode;
}


int main( int, char** ) {
    std::ifstream input_file( "../file_io/file.txt" );

    if( input_file.is_open() ) {
        std::string input_line;
        while( getline( input_file, input_line) ) {
            std::vector< std::string > strings;

            std::split( input_line, ' ', strings );
            std::cout << "Price: " << get_price( input_line ) << " "
                      << "Barcode: " << get_barcode( input_line ) << std::endl;
        }

        input_file.close();
    }

    return 0;
}
