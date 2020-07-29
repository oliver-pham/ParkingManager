/* Citation and Sources...
Final Project Milestone 6
Module: Parking
Filename: Parking.cpp
Version 1.1
Author Phu Thong Pham
Description:
- Defines member functions of "Parking" class
Revision History
-----------------------------------------------------------
Date         Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include <fstream>
#include "Parking.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Utils.h"
#define NOT_FOUND -1

using namespace std;

namespace sdds {
    Parking::Parking()
    {
        m_filename = nullptr;
        m_noOfParkedVehicles = 0;
        setEmpty();
    }

    Parking::Parking(const char* filename, int noOfSpots)
    {
        m_filename = nullptr;
        if (filename && filename[0] != '\0' && noOfSpots >= MIN_PARKING_SPOTS && noOfSpots <= MAX_PARKING_SPOTS)
        {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            m_noOfSpots = noOfSpots;
            m_noOfParkedVehicles = 0;
            for (int i = 0; i < MAX_PARKING_SPOTS; i++)
                m_parkingSpots[i] = nullptr;
        }
        else
            setEmpty();
        
        if (loadDataFile())
        {
            m_menu = Menu("Parking Menu, select an action:");
            m_menu.add("Park Vehicle");
            m_menu.add("Return Vehicle");
            m_menu.add("List Parked Vehicles");
            m_menu.add("Close Parking (End of day)");
            m_menu.add("Exit Program");
            m_vehicleSelection = Menu("Select type of the vehicle:", 1);
            m_vehicleSelection.add("Car");
            m_vehicleSelection.add("Motorcycle");
            m_vehicleSelection.add("Cancel");
        }
        else
        {
            cout << "Error in data file" << endl;
            setEmpty();
        }
    }
    // Set object to an invalid empty state
    void Parking::setEmpty()
    {
        delete[] m_filename;
        m_filename = nullptr;
        m_menu = m_vehicleSelection = Menu();
        m_noOfSpots = 0;
        if (m_noOfParkedVehicles)
        {
            for (int i = 0; i < m_noOfSpots; i++)
            {
                delete m_parkingSpots[i];
                m_parkingSpots[i] = nullptr;
            }
        }
        else
        {
            for (int i = 0; i < MAX_PARKING_SPOTS; i++)
                m_parkingSpots[i] = nullptr;
        }
        m_noOfParkedVehicles = 0;
    }

    bool Parking::isEmpty() const
    {
        return m_filename == nullptr;
    }

    void Parking::status() const
    {
        cout << "****** Seneca Valet Parking ******" << endl;
        cout << "*****  Available spots: ";
        cout.setf(ios::left);
        cout.width(4);
        cout << (m_noOfSpots - m_noOfParkedVehicles) << " *****" << endl;
        cout.unsetf(ios::left);
    }

    void Parking::parkVehicle()
    {
        Vehicle* vehicle = nullptr;
        if (m_noOfParkedVehicles < m_noOfSpots)
        {
            int selection = m_vehicleSelection.run();
            switch (selection)
            {
                case 1:
                    vehicle = new Car;
                    break;
                case 2:
                    vehicle = new Motorcycle;
                    break;
                case 3:
                    cout << "Parking cancelled" << endl;
                    break;
            }
            if (vehicle)
            {
                cin >> *vehicle;
                if (findVehicle(*vehicle) == NOT_FOUND)
                {
                    for (int i = 0; i < m_noOfSpots && !vehicle->getParkingSpot(); i++)
                    {
                        if (m_parkingSpots[i] == nullptr)
                        {
                            m_parkingSpots[i] = move(vehicle);
                            m_parkingSpots[i]->setParkingSpot(i + 1);
                            m_noOfParkedVehicles++;
                            cout << endl << "Parking Ticket" << endl;
                            cout << *m_parkingSpots[i] << endl;
                        }
                    }
                }
                else
                {
                    cout << "Can not park; license plate already in the system!" << endl;
                    delete vehicle;
                }
            }
        }
        else
            cout << "Parking is full" << endl;
    }

    void Parking::returnVehicle()
    {
        int spot;
        char licensePlate[MAX_PLATE_LENGTH + 1];
        
        cout << "Return Vehicle" << endl;
        cout << "Enter Licence Plate Number: ";
        do
        {
            while (!cin.getline(licensePlate, MAX_PLATE_LENGTH + 1, '\n'))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Licence Plate, try again: ";
            }
            
            if (licensePlate[0] == '\0')
                cout << "Invalid Licence Plate, try again: ";
        } while (licensePlate[0] == '\0');
        spot = findVehicle(Vehicle(licensePlate, "AA"));
        if (spot != NOT_FOUND)
        {
            cout << endl << "Returning: " << endl;
            cout << *m_parkingSpots[spot] << endl;
            delete m_parkingSpots[spot];
            m_parkingSpots[spot] = nullptr;
            m_noOfParkedVehicles--;
        }
        else
            cout << "License plate " << licensePlate << " Not found" << endl;
    }

    void Parking::listParkedVehicles() const
    {
        cout << "*** List of parked vehicles ***" << endl;
        for (int i = 0; i < m_noOfSpots; i++)
        {
            if (m_parkingSpots[i])
            {
                cout << *m_parkingSpots[i];
                cout << "-------------------------------" << endl;
            }
        }
    }

    bool Parking::closeParking()
    {
        if (isEmpty())
        {
            cout << "Closing Parking" << endl;
            return true;
        }
        else
        {
            cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
            if (confirmMessage())
            {
                cout << "Closing Parking" << endl;
                for (int i = 0; i < MAX_PARKING_SPOTS && m_noOfParkedVehicles; i++)
                {
                    if (m_parkingSpots[i])
                    {
                        cout << endl << "Towing request" << endl;
                        cout << "*********************" << endl;
                        cout << *m_parkingSpots[i];
                        delete m_parkingSpots[i];
                        m_parkingSpots[i] = nullptr;
                        m_noOfParkedVehicles--;
                    }
                }
                return true;
            }
            else
            {
                cout << "Aborted!" << endl;
                return false;
            }
        }
    }

    bool Parking::exit() const
    {
        cout << "This will terminate the program!" << endl;
        if (confirmMessage())
        {
            cout << "Exiting program!" << endl;
            return true;
        }
        else
            return false;
    }

    bool Parking::loadDataFile()
    {
        char vehicleType;
        Vehicle* vehicle = nullptr;
        ifstream csvFile;
        
        if (!isEmpty())
        {
            csvFile.open(m_filename);
            if (csvFile.is_open())
            {
                while (csvFile && m_noOfParkedVehicles < m_noOfSpots)
                {
                    csvFile >> vehicleType;
                    csvFile.ignore(1, ',');
                    if (csvFile.good())
                    {
                        if (vehicleType == 'M')
                            vehicle = new Motorcycle;
                        else
                            vehicle = new Car;
                        vehicle->setCsv(true);
                        csvFile >> *vehicle;
                        if (csvFile.good() && m_parkingSpots[vehicle->getParkingSpot() - 1] == nullptr)
                        {
                            m_parkingSpots[vehicle->getParkingSpot() - 1] = move(vehicle);
                            m_parkingSpots[vehicle->getParkingSpot() - 1]->setCsv(false);
                            m_noOfParkedVehicles++;
                        }
                        else
                        {
                            delete vehicle;
                            vehicle = nullptr;
                        }
                    }
                }
            }
        }
        csvFile.close();
        
        return (isEmpty() || !csvFile.is_open()) ? true : csvFile.good();
    }

    void Parking::saveDataFile() const
    {
        if (!isEmpty())
        {
            ofstream csvFile(m_filename);
            if (csvFile.is_open())
            {
                for (int i = 0; i < m_noOfSpots; i++)
                {
                    if (m_parkingSpots[i] != nullptr)
                    {
                        m_parkingSpots[i]->setCsv(true);
                        csvFile << *m_parkingSpots[i];
                    }
                }
                csvFile.close();
            }
        }
    }

    int Parking::run()
    {
        int option = 1;
        if (!isEmpty())
        {
            while (option)
            {
                status();
                option = m_menu.run();
                switch (option)
                {
                    case 1:
                        parkVehicle();
                        break;
                    case 2:
                        returnVehicle();
                        break;
                    case 3:
                        listParkedVehicles();
                        break;
                    case 4:
                        option = !closeParking();
                        break;
                    case 5:
                        option = !exit();
                        break;
                    default:
                        break;
                }
            }
            return 0;
        }
        return 1;
    }
    // Find a vehicle with the same license plate number and return its index
    int Parking::findVehicle(const Vehicle& vehicle) const
    {
        int i;
        bool vehicleFound = false;

        for (i = 0; i < m_noOfSpots && !vehicleFound; i++)
        {
            if (m_parkingSpots[i] && *m_parkingSpots[i] == vehicle)
                vehicleFound = true;
        }
        return (vehicleFound) ? --i : NOT_FOUND;
    }

    Parking::~Parking()
    {
        saveDataFile();
        delete[] m_filename;
        for (int i = 0; i < MAX_PARKING_SPOTS && m_noOfParkedVehicles; i++)
        {
            if (m_parkingSpots[i])
            {
                delete m_parkingSpots[i];
                m_parkingSpots[i] = nullptr;
                m_noOfParkedVehicles--;
            }
        }
    }
}
