#include "manager.hpp"


Manager::Manager() :
    data_()
{

}


void Manager::launch_function_async(
        std::function<void( std::atomic_bool* )> function ){
    data_.futures_.emplace_back(
                std::async(
                    std::launch::async, function, &data_.is_running_ ) );
}


void Manager::start(){
    data_.is_running_ = true;
}


void Manager::stop(){
    data_.is_running_ = false;
}


bool Manager::is_running() const{
    return data_.is_running_;
}
