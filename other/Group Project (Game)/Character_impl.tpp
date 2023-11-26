#include "character.h"
#include <iostream>

using namespace std;
Character::Character(){
    agility = 0;
    charisma = 0;
    endurance = 0;
    intelligence = 0;
    strength = 0;
    health = 0;
}

Character::Character(int a, int c, int e, int i, int l, int s, int h){
    agility = a;
    charisma = c;
    endurance = e;
    intelligence = i;
    strength = s;
    health = 200 + (10*h);
}

void Character::promptAllStats(){
    // introduction
    cout << "\nSet stats for your character:\n"
    << "You have 25 points to allocate to these stats:\n"
    << "agility, charisma, endurance, intelligence, luck, strength, health.\n" << endl;

    // get stats for character
    int aTEMP = 0;
    int cTEMP = 0; 
    int eTEMP = 0; 
    int iTEMP = 0; 
    int lTEMP = 0; 
    int sTEMP = 0; 
    int hTEMP = 0;
    int points = 25;
    while(points > 0){
        cout << "How many points would you like to allocate to AGILITY(" << points << " points left):" << endl;
        cin >> aTEMP;
        points -= aTEMP;
        
        cout << "How many points would you like to allocate to CHARISMA(" << points << " points left):" << endl;
        cin >> cTEMP;
        points -= cTEMP;
        
        cout << "How many points would you like to allocate to ENDURANCE(" << points << " points left):" << endl;
        cin >> eTEMP;
        points -= eTEMP;
        
        cout << "How many points would you like to allocate to INTELLIGENCE(" << points << " points left):" << endl;
        cin >> iTEMP;
        points -= iTEMP;
        
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
            cTEMP = 0; 
            eTEMP = 0; 
            iTEMP = 0; 
            lTEMP = 0; 
            sTEMP = 0; 
            hTEMP = 0;
            points = 25;
        }
    }
    agility = aTEMP;
    charisma = cTEMP;
    endurance = eTEMP;
    intelligence = iTEMP;
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
    case 'c':
        return charisma;
        break;
    case 'e':
        return endurance;
        break;
    case 'i':
        return intelligence;
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

void Character::setAgility(int a){
    agility = a;
}

int Character::getCharisma(){
    return charisma;
}

void Character::setCharisma(int c){
    charisma = c;
}

int Character::getEndurance(){
    return endurance;
}

void Character::setEndurance(int e){

}

int Character::getIntelligence(){
    return intelligence;
}

void Character::setIntelligence(int i){
    intelligence = i;
}

int Character::getLuck(){
    return strength;
}

void Character::setLuck(int s){
    strength = s;
}

int Character::getStrength(){
    return strength;
}

void Character::setStrength(int s){
    strength = s;
}

int Character::getHealth(){
    return health;
}

void Character::setHealth(float h){
    health = h;
}

void Character::printStats(){
    cout << "Agility: " << agility << "\n"
        << "Charisma: " << charisma << "\n"
        << "Endurance: " << endurance << "\n"
        << "Intelligence: " << intelligence << "\n"
        << "Luck: " << luck << "\n"
        << "Strength: " << strength << "\n" 
        << "Health: " << health << endl;
}

void Character::printHealth(){
    cout << "Current health: " << health << endl;
}


