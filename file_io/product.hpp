#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>


struct Product {
    Product() = delete;
    ~Product() = default;
    Product( const std::string & file_description );
    Product( const Product & copy );
    Product( Product && move );
    Product & operator=( const Product & copy );
    Product & operator=( Product && move );

    std::string name;
    uint64_t barcode;
    float price;
};

#endif // PRODUCT_HPP
