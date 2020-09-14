#include <iostream>
#include <cctype>
#include <vector>
#include "menuinterface.h"
#include "game.h"
#include "dungeon/basic/basicdungeonlevelbuilder.h"

MenuInterface::MenuInterface(std::ostream &display, std::istream &input) : _display(display), _input(input) {}

void MenuInterface::displayWelcome(std::string author, std::string title){
    _display << "Welcome to: " << title << "\n\t\tDeveloped by " << author << "\n\tCOMP 3023 Software Development with C++" << std::endl;
}

/**
 * @brief run
 * Enters the DungeonBuilder event loop for menu interactions:
 * Display current menu options, wait for user intput, process user input, repeat
 */
void MenuInterface::run(){
    displayMainMenu();
}

/**
 * @brief MenuInterface::displayMainMenu
 */
void MenuInterface::displayMainMenu(){
    bool exit = false;
    do {
        _display << "\nWhat would you like to do?"
                    "\n\t(g)enerate the example level"
                    "\n\t(r)andom dungeon level"
                    "\n\t(q)uit"
                 << std::endl;
        char  input;
        _input >> input;

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

/**
 * @brief MenuInterface::exitDungeonBuilder
 * @return
 */
bool MenuInterface::yesNoConfirmation(){
    char input;
    _input >> input;
    if(tolower(input) == 'y'){
        return true;
    }
    return false;
}

void MenuInterface::generateExampleLevel(){
    _display << "\nCreating Example Dungeon Level..." << std::endl;
    Game::instance()->setDungeonType(std::make_shared<BasicDungeonLevelBuilder>());
    Game::instance()->createExampleLevel();
    _display << "\nDungeon level created!" << std::endl;
}

void MenuInterface::generateRandomLevel(){
    // dungeon settings to gather from user
    std::string levelName{""};
    int rows{0};
    int cols{0};
    char levelType{CHAR_MAX};

    // input validation flag
    bool validInput = false;

    // Level Name
    _display << "\nWhat would you like to call the level?" << std::endl;
    _input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(_input, levelName);

    // Rows
    do{
        _display << "\nHow many rows in " << levelName << "?" << std::endl;
        validInput = getInputNumber(rows);
    } while(not validInput);

    // Columns
    do{
        _display << "\nHow many columns in " << levelName << "?" << std::endl;
        validInput = getInputNumber(cols);
    } while(not validInput);

    // Level Type
    do{
        _display << "\nWhat type of dungeon level is it? (b)asic or (m)agical" << std::endl;
        validInput = inputLevelType(levelType);
    } while(not validInput);

    _display << "\nCreating" << levelName << "..." << std::endl;
    // TODO: Create Level using gathered settings
    _display << "\nName:\t" << levelName << "\nRows:\t" << rows << "\nCols:\t" << cols << "\nType:\t" << levelType << std::endl;

    _display << "\nDungeon level created!" << std::endl;
}

/**
 * @brief MenuInterface::inputLevelType recieves input from the user and determines
 * whther the input is a valid character for dungeon type. Returns boolean
 * @param levelType a reference to where the input will be saved
 * @return true if valid, false otherwise
 */
bool MenuInterface::inputLevelType(char &levelType){
    // check is valid.
    _input >> levelType;
    switch (tolower(levelType)) {
    case 'b':
    case 'm':
        return true;
    default:
        _display << "\nInput Invalid, Please enter a character from the given options." << std::endl;
        _input.clear();
        _input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
}

/**
 * @brief MenuInterface::getInputNumber recieves input from the user and determines
 * whether the input is valid. Clears the input stream if invalid. Returns boolean
 * @param number: a reference to the location where the input should be saved.
 * @return true if number is valid, false otherwise
 */
bool MenuInterface::getInputNumber(int &number){
    // check is valid.
    if(!(_input >> number)){
        _display << "\nInput Invalid, Please enter a number." << std::endl;
        // clear input screen discard previous input
        _input.clear();
        _input.ignore(123, '\n');
        return false;
    }
    return true;
}

void MenuInterface::displayViewMenu(){
    bool exit = false;
    do {
        _display << "\nWhat would you like to do?"
                    "\n\t(d)escribe the dungeon level"
                    "\n\t(v)iew the dungeon level"
                    "\n\t(r)eturn to main menu"
                 << std::endl;
        char  input;
        _input >> input;
        switch (std::tolower(input)) {
        case 'd':
            describeLevel();
            displayExplorationMenu();
            break;
        case 'v':
            displayLevel();
            break;
        case 'r':
            _display << "\nReturn to main menu?" << std::endl;
            exit = yesNoConfirmation();
            break;
        default:
            break;
        }
    } while (not exit);
}

void MenuInterface::describeLevel(){
    // TODO: add model to description
    _display << "\nName:\t" << std::endl;
    _display << "\nSize:\t" << std::endl;
    _display << "\nType:\t" << std::endl;
}

void MenuInterface::displayLevel(){
    _display << "\nName:\t" << std::endl;
    std::vector<std::string> vect = Game::instance()->displayLevel();
    for (int i = 0; i < int(vect.size()); i++){
        _display << vect[i];
    }
    _display << "\nPress Enter to continue...\t" << std::endl;
    // TODO: prompt for 'enter'
}

void MenuInterface::displayExplorationMenu(){
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
            _display << "\nReturn to previous menu?" << std::endl;
            exit = yesNoConfirmation();
            break;
        default:
            break;
        }
    } while (not exit);
}
void MenuInterface::describeRoom(){
    _display << "\nWhich room would you like to describe? " << "(1-4)" << std::endl; // TODO: Max number of rooms: Add to Game class?
    int roomNumber{0};
    for(_input >> roomNumber; _input.fail() or roomNumber < 1 or roomNumber > 4; _input >> roomNumber){
        _input.clear();
        _input.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        _display << "Invalid integer, please choose a room number between "
                 << 1 << '-' << 4
                 << std::endl;
    }
    _display << "Room " << roomNumber << " is..." << std::endl;
    //TODO: output description of dungeon
    _display << "\nPress Enter to continue...\t" << std::endl;
    // TODO: prompt for 'enter'
}
