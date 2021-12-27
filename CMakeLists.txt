cmake_minimum_required(VERSION 3.10)
project(SzeligaEwelina-etap1)

set(CMAKE_CXX_STANDARD 14)

add_executable(SzeligaEwelina-etap1 main.cpp CarSpecification.cpp CarSpecification.h Car.cpp Car.h CarFactory.cpp CarFactory.h SalesDepartment.cpp SalesDepartment.h Motorbike.cpp Motorbike.h Bike.cpp Bike.h Vehicle.cpp Vehicle.h MotorVehicle.cpp MotorVehicle.h BikeBasket.cpp BikeBasket.h UsedMotorVehicleDealer.cpp UsedMotorVehicleDealer.h)
