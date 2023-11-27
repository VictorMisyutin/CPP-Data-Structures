// CombatManager.cpp

#include "CombatManager.h"
#include <iostream>
#include <unistd.h>

using namespace std;
void CombatManager::engage(Character& player, Enemy& enemy) {
    cout << "Battle beginning with " << enemy.getName() << endl;
    enemy.printHealth();
    while (!enemy.isDead() && !player.isDead()) {
        if (playerTurn(player, enemy)) {
            break; // Player's turn
        }
        if (enemyTurn(enemy, player)) {
            break; // Enemy's turn
        }

    }
}

bool CombatManager::playerTurn(Character& player, Enemy& enemy) {
    cout << "Player attacks!" << endl;
    sleep(2);
    if (!checkDodge(player.getAgility(), enemy.getAgility())) {
        int damage = calculateDamage(45, player.getStrength());
        if (checkCriticalHit(player.getLuck())) {
            std::cout << "Critical hit by player!" << std::endl;
            damage *= 2;
        }
        enemy.loseHealth(damage);
    } else {
        std::cout << "Enemy dodged the player's attack!" << std::endl;
    }
    return enemy.isDead();
}

bool CombatManager::enemyTurn(Enemy& enemy, Character& player) {
    cout << enemy.getName() << " attacks!" << endl;
    sleep(2);
    if (!checkDodge(enemy.getAgility(), player.getAgility())) {
        int damage = calculateDamage(45, enemy.getStrength());
        if (checkCriticalHit(enemy.getLuck())) {
            std::cout << "Critical hit by enemy!" << std::endl;
            damage *= 2;
        }
        player.loseHealth(damage);
    } else {
        std::cout << "Player dodged the enemy's attack!" << std::endl;
    }
    return player.isDead();
}

int CombatManager::calculateDamage(int baseDamage, int strength) {
    return baseDamage + (5 * strength);
}

bool CombatManager::checkCriticalHit(int luck) {
    return (rand() % 100) < (30 + luck);
}

bool CombatManager::checkDodge(int attackerAgility, int defenderAgility) {
    int dodgeChance = 20 + defenderAgility - attackerAgility;
    return (rand() % 100) < dodgeChance;
}



