/* Citation and Sources... 
Final Project Milestone 6
Module: ReadWritable
Filename: ReadWritable.cpp
Version 1.0
Author Phu Thong Pham
Description:
- Defines member functions of "ReadWritable" class
Revision History
-----------------------------------------------------------
Date 		Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "ReadWritable.h"

using namespace std;

namespace sdds {
    ReadWritable::ReadWritable()
    {
        isCommaSeparated = false;
    }

    bool ReadWritable::isCsv() const
    {
        return isCommaSeparated;
    }

    void ReadWritable::setCsv(bool value)
    {
        isCommaSeparated = value;
    }

    ostream& operator<<(ostream& ostr, const ReadWritable& writable)
    {
        writable.write(ostr);
        return ostr;
    }

    istream& operator>>(istream& istr, ReadWritable& readable)
    {
        readable.read(istr);
        return istr;
    }

    ReadWritable::~ReadWritable()
    {
        
    }
}
