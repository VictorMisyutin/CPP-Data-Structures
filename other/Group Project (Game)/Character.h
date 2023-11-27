//Character.h


#ifndef CHARACTER_H
#define CHARACTER_H

#include "Room.h"
#include <string>
using namespace std;
class Enemy;
// template <class ItemType>
class Character
{
public:
    Character();
    // Default Constructor for character
    // post: character is initialized
    Character(int a, int l,int s, int h);
    // Overloaded Constructor for character
    // post: character is initialized with a,l,s,h values
    void promptAllStats();
    // user is prompted to fill stats of character
    // pre: Character is initialized
    // post: character has stats
    int getStatByChar(char c);
    // returns stat using a character to select which stat
    // pre: Character is initialized
    // post: nothing
    int getAgility();
    // returns agility
    // pre: Character is initialized
    // post: nothing
    int getLuck();
    // returns luck
    // pre: Character is initialized
    // post: nothing
    int getStrength();
    // returns strength
    // pre: Character is initialized
    // post: nothing
    int getHealth();
    // returns health
    // pre: Character is initialized
    // post: nothing
    void loseHealth(int damage);
    // Character loses some health
    // pre: Character is initialized
    // post: damage is subtracted from health
    void printStats();
    // prints all character stats
    // pre: Character is initialized
    // post: nothing
    void printHealth();
    // prints characters health
    // pre: Character is initialized
    // post: nothing
    bool isDead();
    // returns true if character is dead
    // pre: Character is initialized
    // post: nothing
    void attack(Enemy& enemy);
    // character attacks enemy
    // pre: Character and enemy is initialized
    // post: character attacks enemy using character stats.
    //       enemy will lose health or dodge the attack.
    void usePotion();
    // character will use potion and gain 150 health
    // pre: Character is initialized
    // post: if player has any potions left they will gain 150 health
    //       and lose one potion.
    void gainPotion();
    // character will gain one potion
    // pre: Character is initialized
    // post: Character will gain a potion
    void searchRoom(Room room);
    // character searches room for potions
    // pre: Character and Room are initialized
    // post: Character will gain a potion if they find one
    int getNumPotions();
    // returns number of potion that character has
    // pre: Character is initialized
    // post: returns number of potions in players inventory
private:
    int agility; // stores agility stat
	int healthStat; // stores characters health stat
    int health; // stores character health
    int luck; // stores luck stat
    int numPotions; // stores health potions
    int strength; // stroes strength stat
};

#include "Character_impl.tpp"

#endif



