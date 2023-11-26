#include "character.h"
#include "Enemy.h"
#include <iostream>


using namespace std;
Character::Character(){
    agility = 0;
    strength = 0;
    health = 0;
}

Character::Character(int a, int l, int s, int h){
    agility = a;
    luck = l;
    strength = s;
    health = 200 + (10*h);
}

void Character::promptAllStats(){
    // introduction
    cout << "\nSet stats for your character:\n"
    << "You have 18 points to allocate to these stats:\n"
    << "agility, charisma, endurance, intelligence, luck, strength, health.\n" << endl;

    // get stats for character
    int aTEMP = 0;
    int lTEMP = 0; 
    int sTEMP = 0; 
    int hTEMP = 0;
    int points = 18;
    while(points > 0){
        cout << "How many points would you like to allocate to AGILITY(" << points << " points left):" << endl;
        cin >> aTEMP;
        points -= aTEMP;
        
        cout << "How many points would you like to allocate to LUCK(" << points << " points left):" << endl;
        cin >> lTEMP;
        points -= lTEMP;
        
        cout << "How many points would you like to allocate to STRENGTH(" << points << " points left):" << endl;
        cin >> sTEMP;
        points -= sTEMP;
        
        cout << "How many points would you like to allocate to HEALTH(" << points << " points left):" << endl;
        cin >> hTEMP;
        points -= hTEMP;

        if(points < 0){
            cout << "ERROR, make sure all stats add up to a maximum of 25." << endl;
            aTEMP = 0;
            lTEMP = 0; 
            sTEMP = 0; 
            hTEMP = 0;
            points = 18;
        }
    }
    agility = aTEMP;
    luck = lTEMP;
    strength = sTEMP;
    health = 200 + (10*hTEMP);
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
    return strength;
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
    cout << "Agility: " << agility << "\n"
        << "Luck: " << luck << "\n"
        << "Strength: " << strength << "\n" 
        << "Health: " << health << "\n" << endl;
}

void Character::printHealth(){
    cout << "Current health: " << health << endl;
}

bool Character::isDead(){
    return (health <= 0);
}

void Character::attack(Enemy& enemy){
    int damage = 45;
    damage += (5*strength); // calculate bonus damage due to strength stat

    int range = 20;
    range += 2 * agility; // calculate dodge change due to agility
    int randomNum = rand() %100;

    if(randomNum > range){
        range = 30;
        range += 3 * luck; // calculate critical chance given luck stat
        randomNum = rand() %100;
        if(randomNum < range){
            damage *= 2;
            cout << "Critical Hit!" << endl;
        }
        else{
            cout << "Hit!" << endl;

        }
        enemy.loseHealth(damage);
    }
    else{
        cout << enemy.getName() << " dodged the attack!" <<endl;
    }

}

