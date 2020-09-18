#include "menuinterface.h"
#include "game.h"
#include "core/dungeon/basic/basicdungeonlevelbuilder.h"
#include "core/dungeon/magical/magicaldungeonlevelbuilder.h"
namespace core {

using core::dungeon::basic::BasicDungeonLevelBuilder;
using core::dungeon::magical::MagicalDungeonLevelBuilder;

MenuInterface::MenuInterface(std::ostream &display, std::istream &input) : _display(display), _input(input) {}

void MenuInterface::displayWelcome(const std::string &author, const std::string &title) const{
    _display << "Welcome to: " << title << "\n\t\tDeveloped by " << author << "\n\tCOMP 3023 Software Development with C++" << std::endl;
}

void MenuInterface::run() const{
    bool exit = false;
    do {
        // display current menu
        displayMainMenu();
        // get user input
        char input;
        _input >> input;
        // process user input
        switch (std::tolower(input)) {
        case 'g':
            generateExampleLevel();
            displayViewMenu();
            break;
        case 'r':
            generateRandomLevel();
            displayViewMenu();
            break;
        case 'q':
            _display << "\nAre you sure you want to quit? (y/n)" << std::endl;
            exit = yesNoConfirmation();
            _display << "\nGoodbye!" << std::endl;
            break;
        default:
            break;
        }
    } while (not exit);
}

void MenuInterface::displayMainMenu() const{
    _display << "\nWhat would you like to do?"
                "\n\t(g)enerate the example level"
                "\n\t(r)andom dungeon level"
                "\n\t(q)uit"
             << std::endl;
}

bool MenuInterface::yesNoConfirmation() const{
    char input;
    _input >> input;
    if(tolower(input) == 'y'){
        return true;
    }
    return false;
}

void MenuInterface::generateExampleLevel() const{
    _display << "\nCreating Example Dungeon Level..." << std::endl;
    Game::instance()->setDungeonType(new BasicDungeonLevelBuilder());
    Game::instance()->createExampleLevel();
    _display << "\nDungeon level created!" << std::endl;
}

void MenuInterface::generateRandomLevel() const{
    // get random dungeon settings from user
    _input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string levelName{inputLevelName()};
    int rows{inputNumber(levelName)};
    int cols{inputNumber(levelName)};
    char levelType{inputLevelType()};
    // Create random level
    _display << "\nCreating " << levelName << "..." << std::endl;
    if(levelType == 'b'){
        Game::instance()->setDungeonType(new BasicDungeonLevelBuilder());
    } else {
        Game::instance()->setDungeonType(new MagicalDungeonLevelBuilder());
    }
    Game::instance()->createRandomLevel(levelName, cols, rows);
    _display << "\nDungeon level created!" << std::endl;
}

void MenuInterface::displayViewMenu() const{
    bool exit = false;
    do {
        // display menu
        _display << "\nWhat would you like to do?"
                    "\n\t(d)escribe the dungeon level"
                    "\n\t(v)iew the dungeon level"
                    "\n\t(r)eturn to main menu"
                 << std::endl;
        // get user input
        char  input;
        _input >> input;
        // process intput
        switch (std::tolower(input)) {
        case 'd':
            describeLevel();
            displayExplorationMenu();
            break;
        case 'v':
            displayLevel();
            break;
        case 'r':
//            _display << "\nReturn to main menu? (y/n)" << std::endl;
            exit = true; // yesNoConfirmation();
            break;
        default:
            break;
        }
    } while (not exit);
}


void MenuInterface::displayExplorationMenu() const{
    bool exit = false;
    do {
        _display << "\nWhat would you like to do?"
                    "\n\t(d)escribe a room"
                    "\n\t(r)eturn to previous menu"
                 << std::endl;
        char  input;
        _input >> input;
        switch (std::tolower(input)) {
        case 'd':
            describeRoom();
            break;
        case 'r':
//            _display << "\nReturn to previous menu? (y/n)" << std::endl;
            exit = true; // yesNoConfirmation();
            break;
        default:
            break;
        }
    } while (not exit);
}

void MenuInterface::describeLevel() const{
    _display << Game::instance()->describeLevel() << std::endl;
}

void MenuInterface::displayLevel() const{
    // display level
    std::vector<std::string> vect = Game::instance()->displayLevel();
    for (int i = 0; i < int(vect.size()); i++){
        _display << vect[i] << std::endl;
    }
    // prompt for enter key
    _display << "\nPress Enter to continue...\t" << std::endl;
    std::string input;
    _input.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(_input, input);
}

void MenuInterface::describeRoom() const{
    int maxRooms = Game::instance()->getNumberOfRooms();
    int roomNumber{0};
    // input room number
    _display << "\nWhich room would you like to describe? " << "(1-" << maxRooms << ")" << std::endl;
    for(_input >> roomNumber; _input.fail() or roomNumber < 1 or roomNumber > maxRooms; _input >> roomNumber){
        _input.clear();
        _input.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        _display << "Invalid integer, please choose a room number between "
                 << 1 << '-' << maxRooms
                 << std::endl;
    }
    // display room
    _display << "Room " << roomNumber << " is..." << std::endl;
    _display << Game::instance()->describeRoom(roomNumber) << std::endl;
    // prompt for enter key
    _display << "\nPress Enter to continue...\t" << std::endl;
    std::string input;
    _input.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(_input, input);
}

std::string MenuInterface::inputLevelName() const{
    // check is valid.
    std::string levelName;
    bool validInput = false;
    do{
        // get input
        _display << "\nWhat would you like to call the level?" << std::endl;
        std::getline(_input, levelName);
        // validate input
        if(levelName == ""){
            _display << "\nInput Invalid, Name cannot be blank." << std::endl;
        } else {
            validInput = true;
        }
    } while(not validInput);
    return levelName;
}

char MenuInterface::inputLevelType() const{
    // check is valid.
    char levelType;
    bool validInput = false;
    do{
        // get input
        _display << "\nWhat type of dungeon level is it? (b)asic or (m)agical" << std::endl;
        _input >> levelType;
        // validate input
        switch (tolower(levelType)) {
        case 'b':
        case 'm':
            validInput = true;
            break;
        default:
            _display << "\nInput Invalid, Please enter a character from the given options." << std::endl;
            _input.clear();
            _input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while(not validInput);
    return levelType;
}

int MenuInterface::inputNumber(std::string &levelName) const{
    int number;
    bool validInput = false;
    do{
        // get input and validate
        _display << "\nHow many rows in " << levelName << "?" << std::endl;
        if(!(_input >> number) || number < 1 || number > 4){
            _display << "\nInput Invalid, Please enter a number between 1 & 4." << std::endl;
            // clear input screen discard previous input
            _input.clear();
            _input.ignore(123, '\n');
        } else {
            validInput = true;
        }
    } while(not validInput);
    return number;
}


} // namespace core
