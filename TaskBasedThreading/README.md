# README #

This repo is for testing `std::thread` mechanisms. Current implementation tests three threads operating get/set mechanisms on two objects. The data being accessed is protected using `std::lock_guard< std::mutex >`.

### RUN ###
1. `git clone https://dmillerlaser@bitbucket.org/dmillerlaser/thread-tests.git`
2. `cd thread-tests`
3. `mkdir build`
4. `cd build`
5. `cmake ..`
6. `make`
7. `./thread-tests`