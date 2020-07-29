/* Citation and Sources...
Final Project Milestone 6
Module: Motorcycle
Filename: Motorcycle.cpp
Version 1.0
Author Phu Thong Pham
Description:
- Defines member functions of "Motorcycle" class
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
#include "Motorcycle.h"

using namespace std;

namespace sdds {
    Motorcycle::Motorcycle()
    {
        m_hasSidecar = 0;
    }

    Motorcycle::Motorcycle(const char* licensePlate, const char* makeModel) : Vehicle(licensePlate, makeModel)
    {
        m_hasSidecar = 0;
    }

    ostream& Motorcycle::write(ostream& ostr) const
    {
        if (isEmpty())
            ostr << "Invalid Motorcycle Object" << endl;
        else
        {
            if (isCsv())
                ostr << "M,";
            else
                ostr << "Vehicle type: Motorcycle" << endl;
            Vehicle::write(ostr);
            if (isCsv())
                ostr << m_hasSidecar << endl;
            else
            {
                if (m_hasSidecar)
                    ostr << "With Sidecar" << endl;
            }
        }
        
        return ostr;
    }

    istream& Motorcycle::read(istream& istr)
    {
        string option;
        if (isCsv())
        {
            Vehicle::read(istr);
            istr >> m_hasSidecar;
            istr.ignore(1000, '\n');
        }
        else
        {
            cout << endl << "Motorcycle information entry" << endl;
            Vehicle::read(istr);
            cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
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
            m_hasSidecar = (option == "y" || option == "Y") ? 1 : 0;
        }
        
        return istr;
    }
}
