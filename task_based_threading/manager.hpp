#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <vector>
#include <future>
#include <functional>
#include <atomic>


class Manager
{
public:
    Manager();
    ~Manager();

    void launch_function_async(
            std::function<void(std::atomic_bool*)> function );

    void start();
    void stop();
    bool is_running() const;

private:
    std::vector<std::future<void>> futures_;
    std::atomic_bool is_running_;
};

#endif // MANAGER_HPP
