/* Citation and Sources...
Final Project Milestone 6
Module: Parking
Filename: Parking.cpp
Version 1.1
Author Phu Thong Pham
Description:
- Defines "Parking" class
Revision History
-----------------------------------------------------------
Date         Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__
#include "Menu.h"
#include "Vehicle.h"

namespace sdds {
    const int MAX_PARKING_SPOTS = 100;
    const int MIN_PARKING_SPOTS = 10;

    class Parking
    {
    private:
        char* m_filename;
        Menu m_menu;
        Menu m_vehicleSelection;
        int m_noOfSpots;
        int m_noOfParkedVehicles;
        Vehicle* m_parkingSpots[MAX_PARKING_SPOTS];
        
        bool isEmpty() const;
        void status() const;
        void parkVehicle();
        void returnVehicle();
        void listParkedVehicles() const;
        bool closeParking();
        bool loadDataFile();
        void saveDataFile() const;
        bool exit() const;
        void setEmpty();
        int findVehicle(const Vehicle& vehicle) const;
    public:
        Parking();
        Parking(const char* filename, int noOfSpots);
        Parking(const Parking& parking) = delete;
        Parking& operator=(const Parking& parking) = delete;
        int run();
        ~Parking();
    };
}

#endif
