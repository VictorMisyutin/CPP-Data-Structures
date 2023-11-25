#ifndef CHARACTER_H
#define CHARACTER_H

// #include "ItemType.h"
// #include <string>
// #include <cmath>
// #include <iostream>
// #include <bitset>
using namespace std;
// template <class ItemType>
class Character
{
public:
    Character();
    // Default Constructor for character
    Character(int a, int c, int e, int i, int s, float h);

    int getAgility();

    void setAgility(int a);

    int getCharisma();

    void setCharisma(int c);

    int getEndurance();

    void setEndurance(int e);

    int getIntelligence();

    void setIntelligence(int i);

    int getStrength();

    void setStrength(int s);
    
    float getHealth();
    
    void setHealth(float h);

private:
    int agility;
    int charisma;
    int endurance;
    int intelligence;
    int strength;
	float health; // stores characters health
};

#include "Character_impl.tpp"

#endif
