// Enemy.h


#ifndef ENEMY_H
#define ENEMY_H

#include <string>
using namespace std;
class Character;
class Enemy
{
public:
    Enemy();
    // Default Constructor for Enemy
    // post: Enemy is initialized
    Enemy(int a, int l,int s, int h, string n);
    // Overloaded Constructor for Enemy
    // post: Enemy is initialized with a,l,s,h values
    int getAgility();
    // returns agility
    // pre: Enemy is initialized
    // post: nothing
    int getLuck();
    // returns luck
    // pre: Enemy is initialized
    // post: nothing
    int getStrength();
    // returns strength
    // pre: Enemy is initialized
    // post: nothing
    int getHealth();
    // returns health
    // pre: Enemy is initialized
    // post: nothing
    void loseHealth(int damage);
    // enemy loses some health
    // pre: Enemy is initialized
    // post: damage is subtracted from health
    void printStats();
    // prints all enemy stats
    // pre: Enemy is initialized
    // post: nothing
    void printHealth();
    // prints enemys health
    // pre: Enemy is initialized
    // post: nothing
    string getName();
    // return name of enemy
    // pre: Enemy is initialized
    // post: nothing
    void addAttack(string attk);
    // add attacks to enemies repetoir
    // pre: Enemy is initialized
    // post: attk is added to attack list
    bool isDead() const;
    // check if enemy is dead
    // pre: Enemy is initialized
    // post: nothing
private:
    string name; // stores enemies name
    string attacks[5] = {"", "", "", "", ""}; // stores enemies attacks (maximum of five)
    int numAttacks; // stores number of attacks
    int agility; // stores agility stat
    int luck; // stores luck stat
    int strength; // stores strength stat
	int health; // stores health stat
};

#include "Enemy_impl.tpp"

#endif



