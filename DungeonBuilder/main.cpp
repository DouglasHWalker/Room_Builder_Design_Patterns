#include <iostream>
#include "core/menuinterface.h"
using namespace std;

/**
 * @brief main
 * @return
 */
int main()
{
    MenuInterface menuInterface = MenuInterface(std::cout, std::cin);
    menuInterface.displayWelcome("Douglas Hudson Walker: Huddy007", "Extreme Fully Sick Dungeon Builder 2: The Last Construction");
    menuInterface.run();
    return 0;
}
