#include "manager_data.hpp"

ManagerData::ManagerData() :
    futures_(),
    is_running_( false )
{}


ManagerData::~ManagerData() {
    for( auto & future : futures_ ) future.get();
}
