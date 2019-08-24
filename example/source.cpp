#include <iostream>
#include <vector>
#include <string>
#include "vtk_menu.h"

void foo()
{
    std::cout << "\nWe just ran a custom function for an option!\n";
}
//Example code for vtk_menu:
int main()
{
    vtk::menu myMenu("Opt0#Opt1#Opt2#Opt3", "My Title", "My Message to the user");
    int a = myMenu.open();
    std::cout << "\nThe user has choosen: " << a << "\n";

    a = vtk::inlineMenu("Opt0#Opt1#Opt2#Opt3", "My Inline Title", "My Message to the user");
    std::cout << "\nThe user has choosen: " << a << "\n";


    vtk::menu myOtherMenun("OptionNoFunc#OptionFunc", "Let's try this", "");
    myOtherMenun.items[1].run = foo; //thiss will associate foo with OptionFunc so it will get ran when we choose that.
    myOtherMenun.open();


    std::cin.get();
    return 0;
}

