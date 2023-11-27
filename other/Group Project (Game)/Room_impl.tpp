// Room_impl.cpp


#include "Room.h"

#include <iostream>

Room::Room(int difficulty) : difficulty(difficulty), nextRoom(nullptr) {
    populateRoom();
}

Room::getDifficulty(){
    return difficulty;
}

void Room::populateRoom() {
    enemies.clear();

    if (difficulty == 1) {

        Enemy enemy1(2, 1, 1, 5, "Goblin");
        enemy1.addAttack("Punch");
        enemy1.addAttack("Kick");
        enemies.push_back(enemy1);

        Enemy enemy2(1, 1, 1, 6, "Skeleton");
        enemy2.addAttack("Slash");
        enemy2.addAttack("Stab");
        enemies.push_back(enemy2);
    } else if (difficulty == 2) {

        Enemy enemy1(1, 4, 2, 10, "Zombie");
        enemy1.addAttack("Bite");
        enemy1.addAttack("Slash");
        enemies.push_back(enemy1);

        Enemy enemy2(3, 2, 2, 8, "Vampire");
        enemy2.addAttack("Bite");
        enemy2.addAttack("Claw");
        enemy2.addAttack("Hypnosis");
        enemies.push_back(enemy2);
    } else if (difficulty == 3) {

    	Enemy enemy1(4, 2, 2, 15, "Sentinel");
    	enemy1.addAttack("Lightning Surge");
    	enemy1.addAttack("Spear Charge");
        enemies.push_back(enemy1);

        Enemy enemy2(2, 4, 4, 13, "Lich");
        enemy2.addAttack("Blind");
        enemy2.addAttack("Life Drain");
        enemies.push_back(enemy2);
    }
}

bool Room::allEnemiesDefeated() const {
    for (const auto& enemy : enemies) {
        if (!enemy.isDead()) {
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

std::vector<Enemy>& Room::getEnemies() {
    return enemies;
}



