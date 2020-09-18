#include <iostream>
#include "core/menuinterface.h"
using core::MenuInterface;

int main()
{
    const MenuInterface menuInterface = MenuInterface(std::cout, std::cin);
    menuInterface.displayWelcome("Douglas Hudson Walker: Huddy007", "Dungeon Builder");
    menuInterface.run();
    return 0;
}
