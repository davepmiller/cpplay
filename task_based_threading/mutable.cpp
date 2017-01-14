#include <chrono>
#include <thread>

#include "mutable.hpp"


Mutable::Mutable() :
    data_()
{}


void Mutable::set_mutable_string( std::string input ){
    std::lock_guard < std::mutex > l{ data_.string_mutex_ };
    data_.mutable_string_ = input;
}


std::string Mutable::get_mutable_string(){
    std::lock_guard< std::mutex > l{ data_.string_mutex_ };
    return data_.mutable_string_;
}


void Mutable::infinite_loop( std::atomic_bool * flag ){
    while( *flag ){
        std::lock_guard< std::mutex > l{ data_.string_mutex_ };
        data_.mutable_string_ = "Mutable::infinite_loop";
    }
}


