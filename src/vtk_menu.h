//vtk menu header file
//Vince Tibor Kiss 2019 aug 24.

//vtk menu is a basic solution for adding simple menus to console applications, nothing more, nothing less

#include <iostream>
#include <vector>
#include <string>

//#define VTK_DEBUG

namespace vtk
{
struct menuItem
{
    std::string name;
    void(*run)();
    menuItem();
    menuItem(std::string name);
    menuItem(void(*run)());
    menuItem(std::string name, void(*run)());
};

void setDefaultMenuMsg(std::string msg);
void setDefaultMenuTitle(std::string title);
void setDefaultItemName(std::string name);
void setDefaultItemFunction(void(*function)());

class menu
{
    std::string opt;
public:
    unsigned char style; 

    int open();

    std::vector<menuItem> items;

    std::string title;
    std::string msg;

    void setTitle(std::string newTitle);
    void setMsg(std::string newMsg);

    menu();
    menu(std::string source, std::string title, std::string msg);
};


int inlineMenu(std::string source, std::string title, std::string msg);
menu generateMenu(std::string source);
}