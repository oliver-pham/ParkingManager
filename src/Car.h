/* Citation and Sources...
Final Project Milestone 6
Module: Car
Filename: Car.h
Version 1.0
Author Phu Thong Pham
Description:
- Defines "Car" class
Revision History
-----------------------------------------------------------
Date         Reason
2020/3/27  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
#include <iostream>
#include "Vehicle.h"

namespace sdds {
    class Car : public Vehicle
    {
    private:
        int m_carwash;
    public:
        Car();
        Car(const char* licensePlate, const char* makeModel);
        Car(const Car& car) = delete;
        Car& operator=(const Car& car) = delete;
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::istream& read(std::istream& istr = std::cin);
    };
}
#endif
