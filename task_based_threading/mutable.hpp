#ifndef MUTABLEOBJECT_HPP
#define MUTABLEOBJECT_HPP

#include <string>

#include "mutable_data.hpp"


class Mutable
{
public:
    Mutable();

    void set_mutable_string( std::string );
    std::string get_mutable_string();
    void infinite_loop( std::atomic_bool * flag );

private:
    MutableData data_;
};

#endif // MUTABLEOBJECT_HPP
