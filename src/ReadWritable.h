/* Citation and Sources...
Final Project Milestone 6
Module: ReadWritable
Filename: ReadWritable.h
Version 1.0
Author Phu Thong Pham
Description:
- Defines "ReadWritable" class
Revision History
-----------------------------------------------------------
Date         Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_READWRITABLE_H__
#define SDDS_READWRITABLE_H__
#include <iostream>

namespace sdds {
    class ReadWritable
    {
    private:
        bool isCommaSeparated;
    public:
        ReadWritable();
        bool isCsv() const;
        void setCsv(bool value);
        virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
        virtual std::istream& read(std::istream& istr = std::cin) = 0;
        virtual ~ReadWritable();
    };
    std::ostream& operator<<(std::ostream& ostr, const ReadWritable& writable);
    std::istream& operator>>(std::istream& istr, ReadWritable& readable);
}
#endif
