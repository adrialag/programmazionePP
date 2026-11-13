cmake_minimum_required(VERSION 3.15)
project(Lezione14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall")
find_package(Eigen3 QUIET)
# AddressSanitizer (Lezione 08): oggi spento
# add_compile_options(-fsanitize=address -g)
# add_link_options(-fsanitize=address)
# qui una riga add_executable per esempio
add_executable(stampa stampa.cpp)
add_executable(prodotto prodotto.cpp)
target_link_libraries(prodotto Eigen3::Eigen)