#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <vector>
#include <future>
#include <functional>
#include <atomic>

#include "manager_data.hpp"


class Manager
{
public:
    Manager();

    void launch_function_async(
            std::function<void(std::atomic_bool*)> function );

    void start();
    void stop();
    bool is_running() const;

private:
    ManagerData data_;
};

#endif // MANAGER_HPP
