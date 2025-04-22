cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

find_package(OpenSSL REQUIRED)

# Add the executable
add_executable(HelloWorld main.cpp consolePrinter.cpp login.cpp hash.cpp) 



target_link_libraries(HelloWorld OpenSSL::Crypto)