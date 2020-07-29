/* Citation and Sources...
Final Project Milestone 6
Module: Vehicle
Filename: Vehicle.cpp
Version 1.0
Author Phu Thong Pham
Description:
- Defines member functions of "Vehicle" class
Revision History
-----------------------------------------------------------
Date         Reason
2020/3/25  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include "Utils.h"
#include "Vehicle.h"
#define MAX_MAKEMODEL_LENGTH 60
#define MIN_MAKEMODEL_LENGTH 2

using namespace std;

namespace sdds {
    Vehicle::Vehicle()
    {
        m_licensePlate[0] = '\0';
        m_makeModel = nullptr;
        m_parkingSpotNumber = 0;
    }

    Vehicle::Vehicle(const char* licensePlate, const char* makeModel)
    {
        char* uppercaseLicensePlate;
        m_makeModel = nullptr;
        bool valid = licensePlate && makeModel && licensePlate[0] != '\0' && makeModel[0] != '\0' && strlen(makeModel) > 1 && strlen(licensePlate) <= MAX_PLATE_LENGTH;
        if (valid)
        {
            uppercaseLicensePlate = new char[strlen(licensePlate) + 1];
            strcpy(uppercaseLicensePlate, licensePlate);
            toUpperString(uppercaseLicensePlate);
            strcpy(m_licensePlate, uppercaseLicensePlate);
            setMakeModel(makeModel);
            m_parkingSpotNumber = 0;
            delete[] uppercaseLicensePlate;
        }
        else
            setEmpty();
    }

    int Vehicle::getParkingSpot() const
    {
        return m_parkingSpotNumber;
    }

    void Vehicle::setParkingSpot(int parkingSpotNumber)
    {
        if (parkingSpotNumber >= 0)
            m_parkingSpotNumber = parkingSpotNumber;
        else
            setEmpty();
    }

    bool Vehicle::operator==(const char* licensePlate) const
    {
        if (!isEmpty() && licensePlate && licensePlate[0] != '\0')
        {
            return strcasecmp(licensePlate, m_licensePlate) == 0;
        }
        else
            return false;
    }

    bool Vehicle::operator==(const Vehicle& vehicle) const
    {
        return *this == vehicle.getLicensePlate();
    }

    ostream& Vehicle::write(ostream& ostr) const
    {
        if (!isEmpty())
        {
            if (isCsv())
            {
                ostr << m_parkingSpotNumber << ",";
                ostr << m_licensePlate << ",";
                ostr << m_makeModel << ",";
            }
            else
            {
                ostr << "Parking Spot Number: ";
                if (m_parkingSpotNumber)
                    ostr << m_parkingSpotNumber << endl;
                else
                    ostr << "N/A" << endl;
                ostr << "Licence Plate: " << m_licensePlate << endl;
                ostr << "Make and Model: " << m_makeModel << endl;
            }
        }
        else
            ostr << "Invalid Vehicle Object" << endl;
        
        return ostr;
    }

    istream& Vehicle::read(istream& istr)
    {
        char licensePlate[MAX_PLATE_LENGTH + 1];
        char makeModel[MAX_MAKEMODEL_LENGTH + 1];
        int parkingSpotNumber;
        
        if (isCsv())
        {
            istr >> parkingSpotNumber;
            setParkingSpot(parkingSpotNumber);
            istr.ignore(1, ',');
            
            istr.getline(licensePlate, MAX_PLATE_LENGTH + 1, ',');
            toUpperString(licensePlate);
            strcpy(m_licensePlate, licensePlate);
            
            istr.getline(makeModel, MAX_MAKEMODEL_LENGTH + 1, ',');
            setMakeModel(makeModel);
        }
        else
        {
            cout << "Enter Licence Plate Number: ";
            do
            {
                while (!istr.getline(licensePlate, MAX_PLATE_LENGTH + 1, '\n'))
                {
                    istr.clear();
                    istr.ignore(1000, '\n');
                    cout << "Invalid Licence Plate, try again: ";
                }
                
                if (licensePlate[0] == '\0')
                    cout << "Invalid Licence Plate, try again: ";
            } while (licensePlate[0] == '\0');
            toUpperString(licensePlate);
            strcpy(m_licensePlate, licensePlate);

            cout << "Enter Make and Model: ";
            do
            {
                while (!istr.getline(makeModel, MAX_MAKEMODEL_LENGTH + 1, '\n'))
                {
                    istr.clear();
                    istr.ignore(1000, '\n');
                    cout << "Invalid Make and model, try again: ";
                }
                if (strlen(makeModel) < MIN_MAKEMODEL_LENGTH)
                    cout << "Invalid Make and model, try again: ";
            } while (strlen(makeModel) < MIN_MAKEMODEL_LENGTH);
            setMakeModel(makeModel);
            setParkingSpot(0);
        }
        if (istr.fail())
            setEmpty();
        
        return istr;
    }

    void Vehicle::setEmpty()
    {
        m_licensePlate[0] = '\0';
        setMakeModel(nullptr);
        m_parkingSpotNumber = 0;
    }

    bool Vehicle::isEmpty() const
    {
        return m_makeModel == nullptr;
    }

    const char* Vehicle::getLicensePlate() const
    {
        return m_licensePlate;
    }

    const char* Vehicle::getMakeModel() const
    {
        return m_makeModel;
    }

    void Vehicle::setMakeModel(const char* makeModel)
    {
        delete[] m_makeModel;
        if (makeModel && makeModel[0] != '\0')
        {
            m_makeModel = new char[strlen(makeModel) + 1];
            strcpy(m_makeModel, makeModel);
        }
        else
            m_makeModel = nullptr;
    }

    Vehicle::~Vehicle()
    {
        delete[] m_makeModel;
    }
}
