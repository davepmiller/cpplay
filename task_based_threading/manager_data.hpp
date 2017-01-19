#ifndef MANAGERDATA_HPP
#define MANAGERDATA_HPP

#include <vector>
#include <future>
#include <atomic>


struct ManagerData
{
    ManagerData();
    ~ManagerData();

    std::vector<std::future<void>> futures_;
    std::atomic_bool is_running_;
};

#endif // MANAGERDATA_HPP
