cmake_minimum_required(VERSION 3.15)
project(BasicNeuralPlusPlus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

#Librerie da trovare
find_package(Eigen3 QUIET)
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV ${OpenCV_VERSION} trovata")

# AddressSanitizer
add_compile_options(-fsanitize=address -g)
add_link_options(-fsanitize=address)
add_executable(basic_neural main.cpp matrix.cpp parametricLayer.cpp)

if(Eigen3_FOUND)
    target_link_libraries(basic_neural Eigen3::Eigen)
else()
    message(STATUS "Eigen non trovata: uso libs/eigen")
    target_include_directories(basic_neural PRIVATE libs/eigen)
endif()
target_link_libraries(basic_neural ${OpenCV_LIBS})