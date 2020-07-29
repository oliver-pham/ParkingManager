/* Citation and Sources... 
Final Project Milestone 6
Module: Utils
Filename: Utils.cpp
Version 1.1
Author Phu Thong Pham
Description:
- Defines helper functions
Revision History
-----------------------------------------------------------
Date 		Reason
2020/3/2    Preliminary release
28/3/2020   Added "toUpperString" function
8/4/2020    Added "confirmMessage" function
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <string>
#include "Utils.h"
#define MAX_OPTION_LENGTH 4

using namespace std;

namespace sdds
{
    // Indent based on the indentation level
    void indent(ostream& os, int indentLevel)
    {
        int spaces = indentLevel * 4;
        for (int i = 0; i < spaces; i++)
        {
            os << " ";
        }
    }
    // Convert a C string to an uppercase C string
    void toUpperString(char cstr[])
    {
        for (int i = 0; cstr[i]; i++)
        {
            cstr[i] = toupper(cstr[i]);
        }
    }
    // Print confirmation message and return true if the answer is "yes";
    // Otherwise, return false
    bool confirmMessage()
    {
        string option;
        
        cout << "Are you sure? (Y)es/(N)o: ";
        while (!getline(cin, option, '\n') || (option != "Y" && option != "N" && option != "y" && option != "n"))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
        }
        if (option == "Y" || option == "y")
            return true;
        else
            return false;
    }
}
