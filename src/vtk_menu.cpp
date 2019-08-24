//vtk menu source file
//Vince Tibor Kiss 2019 aug 24.

//vtk menu is a basic solution for adding simple menus to console applications, nothing more, nothing less

#include "vtk_menu.h"

namespace vtk
{

std::string defaultMenuMsg = "Enter option number, or q to exit the menu.";
std::string defaultMenuTitle = "Unnamed Menu";
std::string defaultItemName = "Unnamed Option";
std::string empty = "";

void voidFunc() 
{
    #ifdef VTK_DEBUG
    std::cout << "The selected option has no function associated with it!\n";
    #endif
}
void(*defaultItemFunction)() = voidFunc;


void setDefaultMenuMsg(std::string msg)
{
    defaultMenuMsg = msg;
}
void setDefaultMenuTitle(std::string title)
{
    defaultMenuTitle = title;
}
void setDefaultItemName(std::string name)
{
    defaultItemName = name;
}
void setDefaultItemFunction(void(*function)())
{
    defaultItemFunction = function;
}


int menu::open()
{
    int optNum;
        std::cout << title << ":\n";

        for (int i = 0; i < items.size(); i++)
        {
            std::cout << i << ") " << items[i].name << "\n";
        }

        std::cout << msg << "\n";

        std::cin >> opt;

        if (opt == "q")
        {
            optNum = -1;
        }
        else
        {
            try
            {
                optNum = stoi(opt);
            }
            catch (std::invalid_argument const &e)
            {
                optNum = -2;
            }
        }
        if (optNum >= 0 && optNum > items.size()-1)
        {
            optNum = -2;
        }

        switch (optNum)
        {
        case -1:
            
            return optNum;
            break;
        
        case -2:

            std::cout << "\nInvalid option!\n\n";
            return this->open();
            break;

        default:

            items[optNum].run();
            break;
        }
    
    return optNum;
}

void menu::setTitle(std::string newTitle)
{
    title = newTitle;
}

void menu::setMsg(std::string newMsg)
{
    msg = newMsg;
}



menuItem::menuItem()
{
    run = defaultItemFunction;
    name = defaultItemName;
}

menu generateMenu(std::string source)
{
    menu tmpMenu;
    menuItem tmpItem;
    source.push_back('#');


    //generate from string
    std::vector<menuItem> generatedItems;
    std::string tmpStr = "";

    for (int i = 0; i < source.length(); i++)
    {
        if(source[i] != '#')
        {
            tmpStr.push_back(source[i]);
        }
        else
        {
            generatedItems.push_back(tmpItem);
            generatedItems[generatedItems.size()-1].name = tmpStr;
            tmpStr = "";      
        }
    }

    tmpMenu.items = generatedItems;
    return tmpMenu;
}


menu::menu()
{
    this->msg = defaultMenuMsg;
    this->title = defaultMenuTitle;
}


menu::menu(std::string source, std::string title, std::string msg)
{
    *this = generateMenu(source);

    if (title == "")
    {

        this->title = defaultMenuTitle;
    }
    else
    {
        this->title = title;   
    }
    
    if (msg == "")
    {   
        this->msg = defaultMenuMsg;
    }
    else
    {
        this->msg = msg;
    }
}

int inlineMenu(std::string source, std::string title, std::string msg)
{
    menu inlineMenu(source, title, msg);
    return inlineMenu.open();
}
}