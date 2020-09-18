#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include <iostream>
namespace core {

/**
 * @brief The MenuInterface class
 * Handles the user interation with the Dungeon Builder application. Handles the display of the
 * menu options and inputs from the user, and handles menu navigation. Does not perform any
 * application logic i.e. generating dungeon levels. The MenuInterface collaborates mainly with
 * the Game class by delegating member functions of the game singleton.
 */
class MenuInterface
{
public:
    MenuInterface(std::ostream &display, std::istream &input);
    void displayWelcome(std::string author, std::string title);
    void run();
private:
    std::ostream& _display;
    std::istream& _input;

    void generateExampleLevel();
    void generateRandomLevel();
    bool yesNoConfirmation();
    void displayViewMenu();
    void displayMainMenu();
    void displayLevel();
    void describeLevel();
    void displayExplorationMenu();
    void describeRoom();
    // additonal helper functions
    int inputNumber(std::string &levelName);
    char inputLevelType();
    std::string inputLevelName();
};

} // namespace core
#endif // MENUINTERFACE_H
