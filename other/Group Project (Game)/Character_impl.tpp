// Character_impl.cpp


#include "Character.h"
#include "Enemy.h"
#include <iostream>
#include <limits>

using namespace std;
Character::Character(){
    agility = 0;
    luck = 0;
    strength = 0;
    health = 0;
    numPotions = 1;
}

Character::Character(int a, int l, int s, int h){
    agility = a;
    luck = l;
    strength = s;
    health = 230 + (10*h);
    numPotions = 1;
}

void Character::promptAllStats() {
    // introduction
    cout << "\nSet stats for your character:\n"
         << "You have 22 points to allocate to these stats:\n"
         << "agility, luck, strength, health.\n"
         << endl;

    // get stats for character
    int aTEMP = 0;
    int lTEMP = 0;
    int sTEMP = 0;
    int hTEMP = 0;
    int points = 22;

    while (points > 0) {
        cout << "Agility determines how likely you are to dodge an enemy attack.\n" 
            << "How many points would you like to allocate to AGILITY (" << points << " points left):" << endl;
        cin >> aTEMP;

        while (cin.fail() || aTEMP < 0 || aTEMP > points) {
            cin.clear();  // clear input buffer to restore cin to a usable state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ignore last input
            cout << "Invalid input. Please enter a positive integer less than or equal to " << points << ": ";
            cin >> aTEMP;
        }
        points-=aTEMP;

        cout << "Luck determines how likely you are to find a health potion or get a critical hit.\n"
            << "How many points would you like to allocate to LUCK (" << points << " points left):" << endl;
        cin >> lTEMP;

        while (cin.fail() || lTEMP < 0 || lTEMP > points) {
            cin.clear();  // clear input buffer to restore cin to a usable state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ignore last input
            cout << "Invalid input. Please enter a positive integer less than or equal to " << points << ": ";
            cin >> lTEMP;
        }
        points-=lTEMP;

        cout << "Strength determines you base damage.\n"   
            << "How many points would you like to allocate to STRENGTH (" << points << " points left):" << endl;
        cin >> sTEMP;

        while (cin.fail() || sTEMP < 0 || sTEMP > points) {
            cin.clear();  // clear input buffer to restore cin to a usable state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ignore last input
            cout << "Invalid input. Please enter a positive integer less than or equal to " << points << ": ";
            cin >> sTEMP;
        }
        points-=sTEMP;

        cout << "Health points increase your starting health and how much health you gain from potions.\n" 
            << "How many points would you like to allocate to HEALTH (" << points << " points left):" << endl;
        cin >> hTEMP;

        while (cin.fail() || hTEMP < 0 || hTEMP > points) {
            cin.clear();  // clear input buffer to restore cin to a usable state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ignore last input
            cout << "Invalid input. Please enter a positive integer less than or equal to " << points << ": ";
            cin >> hTEMP;
        }
        points-=hTEMP;

    }

    agility = aTEMP;
    luck = lTEMP;
    strength = sTEMP;
    health = 230 + (10 * hTEMP);
}

int Character::getStatByChar(char c){
    c += 32;
    switch (c)
    {
    case 'a':
        return agility;
        break;
    case 'l':
        return luck;
        break;
    case 's':
        return strength;
        break;
    case 'h':
        return health;
        break;
    default:
        return -1;
        break;
    }

}

int Character::getAgility(){
    return agility;
}

int Character::getLuck(){
    return luck;
}


int Character::getStrength(){
    return strength;
}


int Character::getHealth(){
    return health;
}

void Character::loseHealth(int damage){
    health -= damage;
    if(health<0) health = 0;
    printHealth();
}

void Character::printStats(){
    cout << "Stats\n"
        << "-------------\n" 
        << "Agility: " << agility << "\n"
        << "Luck: " << luck << "\n"
        << "Strength: " << strength << "\n"
        << "Health: " << health  << "\n"
        << "\nCurrent Health: " << health << endl;
}

void Character::printHealth(){
    cout << "Character health: " << health << endl;
}

bool Character::isDead(){
    return (health <= 0);
}

void Character::usePotion(){
    int baseBonus = 150;
    health += baseBonus + (10 * healthStat);
    numPotions--;
}

void Character::gainPotion(){
    numPotions++;
}

int Character::getNumPotions(){
    return numPotions;
}

void Character::searchRoom(Room room){
    if(room.allEnemiesDefeated()){
        if((rand() % 100) < (40 + luck)){
            gainPotion();
            cout << "You have found a poition in the room!" << endl;
        }
        else{
            cout << "You did not find a potion, better luck next time." << endl;
        }

    }
    else{
        cout << "You must clear the room of enemies before you can search to room. " << endl;
    }
}

