// #include "Room.h"

// #include <string>
// #include <iostream>

// using namespace std;

// Room::Room(){
//     name = "";
//     nextRoom = nullptr;
//     numEnemies = 0;
// }

// Room::Room(string n){
//     name = n;
//     nextRoom = nullptr;
//     numEnemies = 0;
// }

// void Room::addEnemy(Enemy enemy){
//     if(numEnemies == 5){
//         cout << "Room already has maximum number of enemies." << endl;
//         return;
//     }
//     enemies[numEnemies] = enemy;
//     numEnemies++;

// }

// void Room::setNextRoom(Room* room){
//     nextRoom = room;
// }
#include "Room.h"
#include <iostream>

Room::Room() : nextRoom(nullptr)
{
    populateRoom();
}

void Room::populateRoom()
{

}

bool Room::allEnemiesDefeated() const
{
    for (const auto& enemy : enemies)
    {
        if (!enemy.isDefeated())
        { // 'isDefeated' is going to have to be a method in Enemy
            return false;
        }
    }
    return true;
}

Room* Room::getNextRoom() const {
    return nextRoom;
}

void Room::setNextRoom(Room* nextRoom) {
    this->nextRoom = nextRoom;
}