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
    void displayWelcome(const std::string author, const std::string title) const;
    void run() const;
private:
    std::ostream& _display;
    std::istream& _input;

    void generateExampleLevel() const;
    void generateRandomLevel() const;
    bool yesNoConfirmation() const;
    void displayViewMenu() const;
    void displayMainMenu() const;
    void displayLevel() const;
    void describeLevel() const;
    void displayExplorationMenu() const;
    void describeRoom() const;
    // additonal helper functions
    int inputNumber(std::string &levelName) const;
    char inputLevelType() const;
    std::string inputLevelName() const;
};

} // namespace core
#endif // MENUINTERFACE_H
