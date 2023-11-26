#include "Enemy.h"
#include <iostream>

using namespace std;
Enemy::Enemy(){
    agility = 0;
    strength = 0;
    health = 0;
    name = "";
}
// Default Constructor for Enemy
Enemy::Enemy(int a, int l,int s, int h, string n){
    agility = a;
    luck = l;
    strength = s;
    health =  75 + (10 * h);
    name = n;
}

int Enemy::getAgility(){
    return agility;
}

int Enemy::getLuck(){
    return strength;
}

int Enemy::getStrength(){
    return strength;
}


int Enemy::getHealth(){
    return health;
}

void Enemy::loseHealth(int damage){
    health -= damage;
    if(health<0) health = 0;
    printHealth();
}

void Enemy::printStats(){
    cout << name << " stats:\n"
        << "Agility: " << agility << "\n"
        << "Luck: " << luck << "\n"
        << "Strength: " << strength << "\n" 
        << "Health: " << health << endl;
}

void Enemy::printHealth(){
    cout << name << " health: " << health << endl;
}

string Enemy::getName(){
    return name;
}

void Enemy::addAttack(string attk){
    bool openSpot = false;
    for(int i = 0 ; i < sizeof(attacks); i++){
        if(attacks[i] == ""){
            attacks[i] = attk;
            openSpot = true;
            break;
        } 
    }
    if(!openSpot)
        cout << "Enemy has enough attacks." << endl;
}

void Enemy::attack(Character& player){
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
        player.loseHealth(damage);
    }
    else{
        cout <<"You dodged the attack!" <<endl;
    }
}

bool Enemy::isDead(){
    return(health <= 0);
}
