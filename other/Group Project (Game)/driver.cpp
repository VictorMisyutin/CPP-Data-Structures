#include "character.h"
#include "Enemy.h"
#include "Room.h"

#include <iostream>
#include <string>

using namespace std;
int main(){
    // introduction

    // create player
    Character player;
    player.promptAllStats();
    player.printStats();

    // create enemies
    Enemy zombie(1, 1, 1, 1, "Zombie");
    zombie.addAttack("Bite");
    zombie.addAttack("Slash");
    Enemy vampire(1,1,1,1,"Vampire");
    vampire.addAttack("Bite");
    vampire.addAttack("Claw");
    vampire.addAttack("Hypnosis");

    while(!zombie.isDead() && !player.isDead()){
        player.attack(zombie);
        zombie.attack(player);
    }
    if(player.isDead()){
        cout << "Player is dead." << endl;
    }
    else{
        cout << zombie.getName() << " is dead" << endl;
    }



    return 0;
}