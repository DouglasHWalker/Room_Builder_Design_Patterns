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
    /**
     * @brief displayWelcome displays a welcome header for the user including
     * an application author and title
     * @param author the author of the application
     * @param title the title of the application
     */
    void displayWelcome(const std::string &author, const std::string &title) const;
    /**
     * @brief run
     * Starts the event loop for the menu interations.
     */
    void run() const;
private:
    /**
     * @brief _display the interface to provide output to
     */
    std::ostream& _display;
    /**
     * @brief _input the interface to get input from
     */
    std::istream& _input;

    /**
     * @brief generateExampleLevel asks a Game object to generate a example level
     * based on some predetermined values for name, type, width and height
     */
    void generateExampleLevel() const;
    /**
     * @brief generateRandomLevel asks a Game object to generate a
     * random dungeon level based on user input values for name, type, width and height
     */
    void generateRandomLevel() const;
    /**
     * @brief yesNoConfirmation get a (y)es or (n)o input confirmation
     * from the user
     * @return true if user answer is (y)es, false otherwise
     */
    bool yesNoConfirmation() const;
    /**
     * @brief displayMainMenu which allows the user to generate
     * a dungeon level or quit the application
     */
    void displayMainMenu() const;
    /**
     * @brief displayViewMenu which allows the user
     * to choose whether to describe or view the dungeon level
     */
    void displayViewMenu() const;
    /**
     * @brief displayExplorationMenu allows user to select
     * specific rooms in the dungeon level to be described
     */
    void displayExplorationMenu() const;
    /**
     * @brief displayLevel displays a graphical representation of the
     * dungeon level.
     */
    void displayLevel() const;
    /**
     * @brief describeLevel displays the dungeon level details
     * level name, level type, level rows, and level columns
     */
    void describeLevel() const;
    /**
     * @brief describeRoom gets a room number from the user and displays
     * the room's description which includes each direction (North, South, East, West)
     * and if they exist, the room's creature and or item
     */
    void describeRoom() const;
    // additonal helper functions
    /**
     * @brief getRowOrColInput gets input for the rows and or columns of the dungeon level,
     * validates the input is a number between the min and max sizes
     * @param levelName
     * @return
     */
    int getRowOrColInput(std::string &levelName) const;
    /**
     * @brief inputLevelType get and validate input for the dungoen level type
     * @return the character representing the dungeon level type
     */
    char inputLevelType() const;
    /**
     * @brief inputLevelName get and validate input for dungeon level name
     * @return the dungeon level name
     */
    std::string inputLevelName() const;
};

} // namespace core
#endif // MENUINTERFACE_H
