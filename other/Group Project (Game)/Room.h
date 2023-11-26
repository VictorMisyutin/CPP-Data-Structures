// #ifndef ROOM_H
// #define ROOM_H

// #include "Enemy.h"
// #include<string>

// using namespace std;
// class Room
// {
// public:
//     Room();
//     Room(string n);
//     void addEnemy(Enemy enemy);
//     void setNextRoom(Room* room);
// private:
//     int numEnemies;
//     string name;
//     Room* nextRoom;
//     Enemy enemies[5];
// };

// #include "Room_impl.tpp"

// #endif

#ifndef ROOM_H
#define ROOM_H

#include "Enemy.h"
#include <string>
#include <array>

using namespace std;

class Room
{
public:
    Room();
    void populateRoom(); // Populates room with random enemies
    bool allEnemiesDefeated() const; // Checks if all enemies in the room are defeated
    Room* getNextRoom() const; // Gets the next room

    void setNextRoom(Room* nextRoom); // Sets the next room

private:
    array<Enemy, 5> enemies; // Array of 5 enemies
    Room* nextRoom;
    int teir;
};

#endif
