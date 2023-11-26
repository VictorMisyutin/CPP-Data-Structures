#include "character.h"
#include "Scenario.h"
#include "ChoiceNode.h"
#include <iostream>

using namespace std;
int main(){
    // introduction
    Character player;
    player.promptAllStats();
    player.printStats();

    // Define scenarios
    Scenario start("Welcome to the Adventure Game! You find yourself in a mysterious land.", "", "", '\0', 0);
    Scenario forest("You enter a dark forest. In front of you, there is a fork in the path.", "", "", 'a', 5);
    Scenario leftPath("You chose to go left. You encounter a wild animal. What do you do?", "You fought the animal and won! You can continue.", "You ran away from the animal.", 'a', 5);
    Scenario rightPath("You chose to go right. You find a hidden path that leads to the next area.", "", "", 'c', 10);
    Scenario cave("You enter a dark cave. You see a mysterious light at the end of the cave.", "", "", 'i', 15);
    Scenario treasure("You approach the light and discover a treasure chest! Congratulations! You found the treasure.", "", "", 'l', 20);

    // Connect scenarios with choices
    ChoiceNode* startChoices = new ChoiceNode("Enter the forest", nullptr);
    start.addChoice(startChoices, &forest);

    ChoiceNode* forestChoices = new ChoiceNode("Go left", nullptr);
    forest.addChoice(forestChoices, &leftPath);

    forestChoices->setNextChoice(new ChoiceNode("Go right", nullptr));
    leftPath.addChoice(new ChoiceNode("Fight", nullptr), &forest);
    leftPath.addChoice(new ChoiceNode("Run", nullptr), &forest);

    rightPath.addChoice(new ChoiceNode("Continue", nullptr), &cave);
    cave.addChoice(new ChoiceNode("Approach the light", nullptr), &treasure);

    // Start the game
    Scenario* currentScenario = &start;

    while (currentScenario != nullptr) {
        currentScenario->printScene();
        currentScenario = currentScenario->makeChoice(player);
    }

    // The game ends when the currentScenario is nullptr.

    return 0;
}