#include "character.h"
    Character::Character(){
        agility = 0;
        charisma = 0;
        endurance = 0;
        intelligence = 0;
        strength = 0;
        health = 0.0;
    }

    Character::Character(int a, int c, int e, int i, int s, float h){
        agility = a;
        charisma = c;
        endurance = e;
        intelligence = i;
        strength = s;
        health = h;
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

    int Character::getStrength(){
        return strength;
    }

    void Character::setStrength(int s){
        strength = s;
    }
    
    float Character::getHealth(){
        return health;
    }
    
    void Character::setHealth(float h){
        health = h;
    }