// Room.h


#ifndef ROOM_H
#define ROOM_H

#include "Enemy.h"
#include <vector>

class Room {
public:
    Room(int difficulty);
    // Constructor with difficulty parameter
    // post: Room is initialized with a specified difficulty

    int getDifficulty();
    // returns the difficulty of the room
    // pre: room is initialized
    // post: returns difficulty of room

    void populateRoom();
    // Populates the room with enemies based on the room's difficulty
    // post: Room is populated with a set of enemies

    bool allEnemiesDefeated() const;
    // Checks if all enemies in the room are defeated
    // pre: Room and enemies are initialized
    // post: Returns true if all enemies in the room are defeated, false otherwise

    Room* getNextRoom() const;
    // Gets the next room in the sequence
    // pre: Room is initialized
    // post: Returns a pointer to the next room

    void setNextRoom(Room* nextRoom);
    // Sets the next room in the sequence
    // pre: Room is initialized
    // post: Sets the pointer to the next room

    std::vector<Enemy>& getEnemies();
    // Gets the enemies in the room for combat purposes
    // pre: Room is initialized and populated with enemies
    // post: Returns a reference to the vector of enemies

private:
    std::vector<Enemy> enemies; // Vector to hold a variable number of enemies
    int difficulty;             // Difficulty level of the room
    Room* nextRoom;             // Pointer to the next room
};

#include "Room_impl.tpp"

#endif // ROOM_H



