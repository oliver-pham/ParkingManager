/* Citation and Sources...
Final Project Milestone 6
Module: Vehicle
Filename: Vehicle.h
Version 1.0
Author Phu Thong Pham
Description:
- Defines "Vehicle" class
Revision History
-----------------------------------------------------------
Date         Reason
2020/3/25  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__
#include <iostream>
#include "ReadWritable.h"

namespace sdds {
    const int MAX_PLATE_LENGTH = 8;

    class Vehicle : public ReadWritable
    {
    private:
        char m_licensePlate[MAX_PLATE_LENGTH + 1];
        char* m_makeModel;
        int m_parkingSpotNumber;
    protected:
        void setEmpty();
        bool isEmpty() const;
        const char* getLicensePlate() const;
        const char* getMakeModel() const;
        void setMakeModel(const char* makeModel);
    public:
        Vehicle();
        Vehicle(const char* licensePlate, const char* makeModel);
        Vehicle(const Vehicle& vehicle) = delete;
        Vehicle& operator=(const Vehicle& vehicle) = delete;
        int getParkingSpot() const;
        void setParkingSpot(int parkingSpotNumber);
        bool operator==(const char* licensePlate) const;
        bool operator==(const Vehicle& vehicle) const;
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::istream& read(std::istream& istr = std::cin);
        virtual ~Vehicle();
    };
}
#endif
