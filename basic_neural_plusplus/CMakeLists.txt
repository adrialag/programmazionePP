cmake_minimum_required(VERSION 3.15)    #versio di CMake
project(BasicNeuralPlusPlus)            #nome del progetto
set(CMAKE_CXX_STANDARD 17)              #c++ da usare

#Librerie da utilizzare
find_package(Eigen3 QUIET)
find_package(OpenCV REQUIRED)

#Executable
add_executable(basic_neural main.cpp)   #target cosa andare a cercare come eseguibile
add_executable(lab1 lab/lab1.cpp)
#andiamo ad aggiungere le librerie necessarie al progetto
#eigen è una libreria header-only non è necessario compilarla

#Target a tutti le app
#Basic_neural
target_link_libraries(basic_neural Eigen3::Eigen)
target_link_libraries(basic_neural ${OpenCV_LIBS})
#lab1
target_link_libraries(lab1 ${OpenCV_LIBS})
target_link_libraries(lab1 Eigen3::Eigen)