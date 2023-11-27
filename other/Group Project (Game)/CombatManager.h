// CombatManager.h


#ifndef COMBATMANAGER_H
#define COMBATMANAGER_H

#include "Character.h"
#include "Enemy.h"

class CombatManager {
public:
    static void engage(Character& player, Enemy& enemy);
    // Engages in combat between a player and an enemy
    // pre: Player and enemy are initialized and not dead
    // post: Conducts the combat sequence between player and enemy

private:
    static bool playerTurn(Character& player, Enemy& enemy);
    // Handles the player's turn in combat
    // pre: Player and enemy are initialized
    // post: Performs player's attack on enemy; returns true if enemy is dead

    static bool enemyTurn(Enemy& enemy, Character& player);
    // Handles the enemy's turn in combat
    // pre: Enemy and player are initialized
    // post: Performs enemy's attack on player; returns true if player is dead

    static int calculateDamage(int baseDamage, int strength);
    // Calculates the damage dealt by an attack
    // pre: baseDamage and strength are provided
    // post: Returns the total damage value

    static bool checkCriticalHit(int luck);
    // Determines if an attack results in a critical hit
    // pre: luck value is provided
    // post: Returns true if a critical hit occurs

    static bool checkDodge(int attackerAgility, int defenderAgility);
    // Determines if an attack is dodged by the defender
    // pre: Attacker's agility and defender's agility are provided
    // post: Returns true if the attack is dodged
};

#include "CombatManager_impl.tpp"

#endif



