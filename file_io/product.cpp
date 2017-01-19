#include <iostream>

#include "product.hpp"


Product::Product( const Product & other ) :
    name( other.name ),
    barcode( other.barcode ),
    price( other.price )
{}


Product::Product( const std::string & file_description ) {
    std::cout << file_description << std::endl;
}


Product::Product( Product && other ) :
    name(),
    barcode( 0 ),
    price( 0 )
{
    *this = std::move( other );
}


Product & Product::operator=( const Product & other ) {
    if( this != &other )
    {
        name = other.name;
        barcode = other.barcode;
        price = other.price;
    }
    return *this;
}


Product & Product::operator=( Product && other ) {
    if( this != &other ){
        name = std::move( other.name );
        barcode = other.barcode;
        price = other.price;
    }
    return *this;
}
