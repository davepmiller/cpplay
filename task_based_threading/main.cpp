#include <iostream>

#include <mutable.hpp>
#include <manager.hpp>
#include <utility.hpp>


int main() {

    Manager manager;
    manager.start();

    auto objects = std::vector<std::shared_ptr<Mutable>>{
            std::make_shared<Mutable>(), std::make_shared<Mutable>() };

    Utility utility{ manager };
    utility.launch_member_functions( objects );
    utility.launch_static_functions( objects );
    utility.limited_blocking_loop( objects );

    manager.stop();

    return 0;
}
