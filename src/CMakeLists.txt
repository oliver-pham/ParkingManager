cmake_minimum_required(VERSION 3.0)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ParkingManager
        VERSION 1.0.0
        LANGUAGES CXX)
# Library Modules
add_library(Car Car.cpp Car.h)
add_library(Menu Menu.cpp Menu.h)
add_library(Motorcycle Motorcycle.cpp Motorcycle.h)
add_library(Parking Parking.cpp Parking.h)
add_library(ReadWritable ReadWritable.cpp ReadWritable.h)
add_library(Vehicle Vehicle.cpp Vehicle.h)
add_library(Utils Utils.cpp Utils.h)

add_executable(ParkingManager
    ParkingAppTester_prof.cpp 
)

target_link_libraries(Menu
    PRIVATE Utils    
)

target_link_libraries(Vehicle
    PUBLIC ReadWritable    
)

target_link_libraries(Motorcycle
    PUBLIC Vehicle    
)

target_link_libraries(Car
    PUBLIC Vehicle    
)

target_link_libraries(Parking
    PUBLIC Menu Vehicle
    PRIVATE Utils Car Motorcycle   
)
target_link_libraries(ParkingManager PRIVATE Parking)

