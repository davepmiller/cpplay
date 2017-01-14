#ifndef MUTABLE_DATA_HPP
#define MUTABLE_DATA_HPP

#include <string>
#include <mutex>
#include <atomic>


struct MutableData
{
    MutableData();

    std::string mutable_string_;
    std::mutex string_mutex_;
};

#endif // MUTABLE_DATA_HPP
