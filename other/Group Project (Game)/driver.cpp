// driver.cpp

#include <iostream>
#include <string>
#include "Character.h"
#include "Room.h"
#include "CombatManager.h"
#include "time.h"
using namespace std;

int main() {
    // introduction
    cout << "\nWelcome to the Labyrinth of Gold!\n"
        << "------------------------------------------------\n"
        << "Embark on a daring adventure where you, a brave hero,\n"
        << "must navigate through treacherous rooms filled with challenges and enemies.\n"
        << "Your goal: to reach the heart of the labyrinth and claim the legendary treasure!\n"
        << "But beware, each room presents unique obstacles where your character will be tested.\n"
        << "Allocate your points wisely and face the challenges that lie ahead.\n\n";

    srand(time(NULL));

    bool restartGame; 
    do {
        restartGame = false;
        string choice = "";
        bool validChoice = false;
        Character player;
        player.promptAllStats();
        player.printStats();

        Room room1(1), room2(2), room3(2), room4(3);
        room1.setNextRoom(&room2);
        room2.setNextRoom(&room3);
        room3.setNextRoom(&room4);

        Room* currentRoom = &room1;

        while (currentRoom != nullptr && !player.isDead()) {
            for (Enemy& enemy : currentRoom->getEnemies()) {
                cout << "\nYou have encountered a " << enemy.getName() << endl; 
                if(player.getNumPotions() > 0){
                    while(!validChoice){
                        cout << "Would you like to use a potion? (1) yes, (2) no" << endl;
                        cin >> choice;
                        if(choice == "1"){
                            validChoice = true;
                            player.usePotion();
                        }
                        else if(choice == "2")
                            validChoice = true;
                    }
                    validChoice = false;
                }
                CombatManager::engage(player, enemy);

                if (player.isDead()) {
                    cout << "You have been defeated." << endl;
                    break;
                }
            }

            if (player.isDead()) {
                break;
            }

            if (!currentRoom->allEnemiesDefeated()) {
                cout << "There are still enemies in the room!" << endl;
                break;
            }

            cout << "You have cleared the room, searching for potions.\n" << endl;
            player.searchRoom(*currentRoom);

            // So we should maybe ask the player for next action here. Like this:
            player.printHealth();
            while(!validChoice){
                cout << "Would you like to (1) Move to the next room, (2) Retreat, or (3) Restart the game? Enter your choice: ";
                cin >> choice;

                if (choice == "2") {
                    cout << "Ending the game. Thank you for playing!" << endl;
                    validChoice = true;
                    return 0;
                } else if (choice == "3") {
                    validChoice = true;
                    restartGame = true;
                    break;
                } else if (choice == "1") {
                    validChoice = true;
                    cout << "Moving to the next room..." << endl;
                    currentRoom = currentRoom->getNextRoom();
                }
            }
            validChoice = false;
        }

        if (!player.isDead() && !restartGame) {
            cout << "Congratulations! You've cleared all rooms." << endl;
        }

        if (!restartGame) {
            cout << "Do you want to play again? (yes/no): ";
            string answer;
            cin >> answer;
            restartGame = (answer == "yes");
        }
    } while (restartGame);

    return 0;
}
