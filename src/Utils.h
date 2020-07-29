/* Citation and Sources... 
Final Project Milestone 6
Module: Utils
Filename: Utils.h
Version 1.1
Author Phu Thong Pham
Description:
- Declares helper functions
Revision History
-----------------------------------------------------------
Date 		Reason
2020/3/2 	Preliminary release
2020/3/28   Added "toUpperString" function
2020/4/8    Added "confirmMessage" function
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>

namespace sdds
{
    void indent(std::ostream& os = std::cout, int indentLevel = 0);
    void toUpperString(char cstr[]);
    bool confirmMessage();
}

#endif
