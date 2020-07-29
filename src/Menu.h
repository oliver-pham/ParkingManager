/* Citation and Sources... 
Final Project Milestone 6
Module: Menu
Filename: Menu.h
Version 1.0
Author Phu Thong Pham
Description:
- Defines "MenuItem" class & "Menu" class
Revision History
-----------------------------------------------------------
Date 		Reason
2020/3/2 	Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>

namespace sdds
{
    const int MAX_NO_OF_ITEMS = 10;
    
    class Menu;

    class MenuItem
    {
        char* itemName;
        
        MenuItem();
        MenuItem(const char* name);
        MenuItem(const MenuItem& item) = delete;
        MenuItem& operator=(const MenuItem& item) = delete;
        std::ostream& display(std::ostream& os = std::cout) const;
        // Additional Member functions
        bool isEmpty() const;
        bool setName(const char* name);
        ~MenuItem();
        friend class Menu;
    };

    class Menu
    {
    private:
        MenuItem title;
        MenuItem* items[MAX_NO_OF_ITEMS];
        int indentLevel;
        int numOfItems;
    public:
        Menu();
        Menu(const char* menuTitle, int menuIndentLvl = 0);
        Menu(const Menu& menu);
        // Operator overloads
        Menu& operator=(const Menu& menu);
        Menu& operator=(const char* menuTitle);
        Menu& operator<<(const char* menuTitle);
        operator bool() const;
        operator int() const;
        // Member functions
        bool isEmpty() const;
        std::ostream& display(std::ostream& os = std::cout) const;
        void add(const char* menuTitle);
        int run() const;
        // Additional Member functions
        void emptyItems();
        ~Menu();
    };
}

#endif
