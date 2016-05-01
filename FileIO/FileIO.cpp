#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main( int argc, char** argv )
{
    ifstream inputFile( "../FileIO/File.txt" );

    if( inputFile.is_open() )
    {
        string inputLine;
        while( getline( inputFile, inputLine) )
        {
            cout << inputLine << endl;
        }

        inputFile.close();
    }

    return 0;
}
