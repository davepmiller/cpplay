#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "manager.hpp"
#include "mutable.hpp"


class Utility
{
public:
    Utility( Manager & manager );

    void infinite_loop_mutate( std::vector<std::shared_ptr<Mutable>> objects );
    void infinite_loop_print( std::vector<std::shared_ptr<Mutable>> objects );
    void limited_blocking_loop( std::vector<std::shared_ptr<Mutable>> objects );
    void launch_member_functions( std::vector<std::shared_ptr<Mutable>> objects );
    void launch_static_functions( std::vector<std::shared_ptr<Mutable>> objects );
    void launch_member_function( Mutable & obj );

private:
    Manager & manager_;
};

#endif // UTILITY_HPP
