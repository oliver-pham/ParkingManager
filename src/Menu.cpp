/* Citation and Sources... 
Final Project Milestone 6
Module: Menu
Filename: Menu.cpp
Version 1.0
Author Phu Thong Pham
Description:
- Defines member functions & operator overloads of "MenuItem" class
- Defines member functions & operator overloads of "Menu" class
Revision History
-----------------------------------------------------------
Date 		Reason
2020/3/2 	Preliminary release
2020/3/14 	Debugged Memory Leaks
2020/3/16   Set instance to an invalid empty state if the
            assigned C-string title is invalid
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include "Utils.h"
#include "Menu.h"

using namespace std;

namespace sdds
{
    MenuItem::MenuItem()
    {
        itemName = nullptr;
    }
    
    MenuItem::MenuItem(const char* name)
    {
        itemName = nullptr;
        setName(name);
    }

    ostream& MenuItem::display(ostream& os) const
    {
        if (!isEmpty())
        {
            os << itemName << endl;
        }
        return os;
    }
    // Check if a Menu Item is empty
    bool MenuItem::isEmpty() const
    {
        return itemName == nullptr;
    }
    // Validate & set the name of a Menu Item
    bool MenuItem::setName(const char* name)
    {
        delete[] itemName;
        if (name && strcmp(name, ""))
        {
            itemName = new char[strlen(name) + 1];
            strcpy(itemName, name);
            return true;
        }
        else
        {
            itemName = nullptr;
            return false;
        }
    }

    MenuItem::~MenuItem()
    {
        delete[] itemName;
    }
    
    Menu::Menu()
    {
        title.setName(nullptr);
        indentLevel = 0;
        numOfItems = 0;
    }

    Menu::Menu(const char* menuTitle, int menuIndentLvl)
    {
        if (title.setName(menuTitle))
            indentLevel = menuIndentLvl;
        else
            indentLevel = 0;
        numOfItems = 0;
    }
    
    Menu::Menu(const Menu& menu)
    {
        numOfItems = 0;
        *this = menu;
    }

    Menu& Menu::operator=(const Menu& menu)
    {
        if (this != &menu)
        {
            title.setName(menu.title.itemName);
            indentLevel = menu.indentLevel;
            if (numOfItems)
                emptyItems();
            for (int i = 0; i < menu.numOfItems; i++)
            {
                add(menu.items[i]->itemName);
            }
        }
        return *this;
    }
    
    Menu& Menu::operator=(const char* menuTitle)
    {
        if (!title.setName(menuTitle))
        {
            emptyItems();
            indentLevel = 0;
        }
        return *this;
    }
    
    Menu& Menu::operator<<(const char* menuTitle)
    {
        add(menuTitle);
        return *this;
    }

    Menu::operator bool() const
    {
        return !isEmpty();
    }
    
    Menu::operator int() const
    {
        return run();
    }
    
    bool Menu::isEmpty() const
    {
        return title.isEmpty();
    }
    
    ostream& Menu::display(ostream& os) const
    {
        if (isEmpty())
        {
            os << "Invalid Menu!" << endl;
        }
        else
        {
            indent(os, indentLevel);
            title.display(os);
            if (!numOfItems)
                os << "No Items to display!" << endl;
            else
            {
                for (int i = 0; i < numOfItems; i++)
                {
                    indent(os, indentLevel);
                    os << i + 1 << "- ";
                    items[i]->display(os);
                }
                indent(os, indentLevel);
                os << "> ";
            }
        }
        return os;
    }
    // Add a Menu Item to the "items" list
    void Menu::add(const char* menuTitle)
    {
        if (!isEmpty() && numOfItems < MAX_NO_OF_ITEMS)
        {
            items[numOfItems] = new MenuItem;
            if (!items[numOfItems++]->setName(menuTitle))
            {
                emptyItems();
                title.setName(nullptr);
            }
        }
    }
    // Prompt for menu option
    int Menu::run() const
    {
        int option = 0;
        display();
        if (numOfItems)
        {
            while (!(cin >> option))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Integer, try again: ";
            }
            while (option <= 0 || option > numOfItems)
            {
                cin.ignore(1000, '\n');
                cout << "Invalid selection, try again: ";
                cin >> option;
            }
            cin.ignore(1000, '\n');
        }
        return option;
    }
    // Empty all Menu Items
    void Menu::emptyItems()
    {
        for (int i = 0; i < numOfItems; i++)
        {
            delete items[i];
            items[i] = nullptr;
        }
        numOfItems = 0;
    }
    
    Menu::~Menu()
    {
        emptyItems();
    }
}
