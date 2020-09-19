#ifndef DOORWAY_H
#define DOORWAY_H
#include "roomedge.h"
namespace core::dungeon {
/**
 * @brief The Doorway class representing a doorway in a room,
 * is a type of room edge @sa core:;dungeon::RoomEdge). Additonally,
 * handles doorway specific operations; connecting to an opposite doorway,
 * and determineing whether the doorway is an entry or exit.
 */
class Doorway : public RoomEdge
{
public:
    virtual ~Doorway() {
        delete _opposite;
    }
    virtual std::string description() const override = 0;
    virtual char displayCharacter() const  override = 0;
    /**
     * @brief isPassage determine whether this doorway is a passage between rooms i.e. is a doorwya but is not an entry or exit
     * @return true if doorway is a passage, false otherwise
     */
    bool isPassage() const override;
    /**
     * @brief connect this doorway to the given doorway
     * @param opposite the doorway to connect to
     */
    void connect(Doorway* const opposite);
    /**
     * @brief isEntrance determine whether this doorway is an entry
     * @return true if doorway is an entrance, false otherwise
     */
    bool isEntrance() const;
    /**
     * @brief isExit determine whether this doorway is an exit
     * @return true if doorway is an exit, false otherwise
     */
    bool isExit() const;
    // WARNING: public getters not in class diagram
    void setEntry(const bool isEntry);
    void setExit(const bool isExit);

protected:
    /**
     * @brief _isEntry is the doorway an entry
     */
    bool _isEntry = false;
    /**
     * @brief _isEntry is the doorway an exit
     */
    bool _isExit = false; // WARNING: may need to revise entry exit
    /**
     * @brief _opposite the connecting doorway to this doorway
     */
    Doorway* _opposite;
};

} // namespace core::dungeon
#endif // DOORWAY_H
