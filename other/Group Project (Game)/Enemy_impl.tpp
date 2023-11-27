// Enemy_impl.cpp


#include "Enemy.h"
#include "Character.h"
#include <iostream>

using namespace std;
Enemy::Enemy(){
    agility = 0;
    luck = 0;
    strength = 0;
    health = 0;
    name = "";
    numAttacks = 0;
}
// Default Constructor for Enemy
Enemy::Enemy(int a, int l,int s, int h, string n){
    agility = a;
    luck = l;
    strength = s;
    health =  75 + (10 * h);
    name = n;
    numAttacks = 0;
}

int Enemy::getAgility(){
    return agility;
}

int Enemy::getLuck(){
    return luck;
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
    if(numAttacks == 5){
        cout << "Enemy has max number of attacks." << endl;
        return;
    }
    for(size_t i = 0; i < sizeof(attacks)/sizeof(attacks[0]); i++){
        if(attacks[i] == ""){
            attacks[i] = attk;
            numAttacks++;
            break;
        }
    }
}


// void Enemy::attack(Character& player){
//     string attackUsed;
//     int randomAttk = rand() % numAttacks;
//     attackUsed = attacks[randomAttk];
//     cout << name << " used " << attackUsed << endl;

//     int damage = 45;
//     damage += (5*strength); // Bonus damage due to strength stat

//     int range = 20;
//     range += 2 * agility; // Dodge change due to agility
//     int randomNum = rand() %100;

//     if(randomNum > range){
//         range = 30;
//         range += 3 * luck; // Critical chance given luck stat
//         randomNum = rand() %100;
//         if(randomNum < range){
//             damage *= 2;
//             cout << "Critical Hit!" << endl;
//         }
//         else{
//             cout << "Hit!" << endl;

//         }
//         player.loseHealth(damage);
//     }
//     else{
//         cout <<"You dodged the attack!" <<endl;
//     }
// }

bool Enemy::isDead() const {
    return (health <= 0);
}



