#ifndef CHARACTER_H
#define CHARACTER_H

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
    void attack(Enemy& enemy);
    // character attacks enemy
    // pre: Character and enemy is initialized
    // post: character attacks enemy using character stats.
    //       enemy will lose health or dodge the attack.
private:
    int agility; // stores agility stat
    int luck; // stores luck stat
    int strength; // stroes strength stat
	int health; // stores characters health stat
};

#include "Character_impl.tpp"

#endif
