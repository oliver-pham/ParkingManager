/* Citation and Sources...
Final Project Milestone 6
Module: Car
Filename: Car.cpp
Version 1.0
Author Phu Thong Pham
Description:
- Defines member functions of "Car" class
Revision History
-----------------------------------------------------------
Date         Reason
2020/3/27  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "Vehicle.h"
#include "Car.h"

using namespace std;

namespace sdds {
    Car::Car()
    {
        m_carwash = 0;
    }

    Car::Car(const char* licensePlate, const char* makeModel) : Vehicle(licensePlate, makeModel)
    {
        m_carwash = 0;
    }

    ostream& Car::write(ostream& ostr) const
    {
        if (isEmpty())
            ostr << "Invalid Car Object" << endl;
        else
        {
            if (isCsv())
                ostr << "C,";
            else
                ostr << "Vehicle type: Car" << endl;
            Vehicle::write(ostr);
            if (isCsv())
                ostr << m_carwash << endl;
            else
                ostr << ((m_carwash) ? "With Carwash" : "Without Carwash") << endl;
        }
        
        return ostr;
    }

    istream& Car::read(istream& istr)
    {
        string option;
        if (isCsv())
        {
            Vehicle::read(istr);
            istr >> m_carwash;
            istr.ignore(1000, '\n');
        }
        else
        {
            cout << endl << "Car information entry" << endl;
            Vehicle::read(istr);
            cout << "Carwash while parked? (Y)es/(N)o: ";
            do
            {
                while (!(istr >> option))
                {
                    istr.clear();
                    istr.ignore(1000, '\n');
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                }
                
                if (option != "y" && option != "Y" && option != "n" && option != "N")
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            } while (option != "y" && option != "Y" && option != "n" && option != "N");
            m_carwash = (option == "y" || option == "Y") ? 1 : 0;
        }
        
        return istr;
    }
}
