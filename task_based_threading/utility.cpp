#include <iostream>
#include "utility.hpp"


Utility::Utility( Manager & manager ) :
    manager_( manager )
{}


void Utility::infinite_loop_mutate(
        std::vector<std::shared_ptr<Mutable>> objects ) {
    while(manager_.is_running() ) {
        for( auto obj : objects ) {
            obj->set_mutable_string( "Utility::infinite_loop_mutate" );
        }
    }
}


void Utility::infinite_loop_print(
        std::vector<std::shared_ptr<Mutable>> objects ) {
    auto obj_count = 0;
    while( manager_.is_running() ) {
        for( auto & obj : objects ) {
            std::cout << obj_count++ << ": "
                      << obj->get_mutable_string() << "\n";
        }
    }
}


void Utility::limited_blocking_loop(
        std::vector<std::shared_ptr<Mutable>> objects ) {
    for( auto i = 0; i < 1000000; ++i ) {
        for( auto obj : objects ) {
            obj->set_mutable_string( "Utility::limited_blocking_loop" );
        }
    }
}


void Utility::launch_member_functions(
        std::vector<std::shared_ptr<Mutable>> objects ) {
    for( auto & obj : objects ) {
        launch_member_function( *obj );
    }
}


void Utility::launch_member_function( Mutable & obj ) {
   manager_.launch_function_async(
                std::bind( &Mutable::infinite_loop,
                           &obj,
                           std::placeholders::_1 ) );
}


void Utility::launch_static_functions(
        std::vector<std::shared_ptr<Mutable>> objects ) {
   manager_.launch_function_async(
                std::bind( &Utility::infinite_loop_mutate, this, objects  ) );
   manager_.launch_function_async(
                std::bind( &Utility::infinite_loop_print, this, objects ) );
}
