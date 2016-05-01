# README #

This repo is for testing `std::thread` mechanisms. Current implementation tests three threads operating get/set mechanisms on two objects. The data being accessed is protected using `std::lock_guard< std::mutex >`.
