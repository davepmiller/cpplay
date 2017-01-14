#include "manager.hpp"


Manager::Manager() :
    futures_()
{

}


Manager::~Manager(){
    for( auto & future : futures_ ) future.get();
}


void Manager::launch_function_async(
        std::function<void( std::atomic_bool* )> function ){
    futures_.emplace_back(
                std::async( std::launch::async, function, &is_running_ ) );
}


void Manager::start(){
    is_running_ = true;
}


void Manager::stop(){
    is_running_ = false;
}


bool Manager::is_running() const{
    return is_running_;
}
