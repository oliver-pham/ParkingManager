/* Citation and Sources...
Final Project Milestone 6
Module: Motorcycle
Filename: Motorcycle.h
Version 1.0
Author Phu Thong Pham
Description:
- Defines "Motorcycle" class
Revision History
-----------------------------------------------------------
Date         Reason
2020/3/27  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_MOTORCYCLE_H__
#define SDDS_MOTORCYCLE_H__
#include <iostream>
#include "Vehicle.h"

namespace sdds {
    class Motorcycle: public Vehicle
    {
    private:
        int m_hasSidecar;
    public:
        Motorcycle();
        Motorcycle(const char* licensePlate, const char* makeModel);
        Motorcycle(const Motorcycle& motorcycle) = delete;
        Motorcycle& operator=(const Motorcycle& motorcycle) = delete;
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::istream& read(std::istream& istr = std::cin);
    };
}
#endif
