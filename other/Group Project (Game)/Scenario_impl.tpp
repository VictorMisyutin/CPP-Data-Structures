#include "Scenario.h"
#include <iostream>
using namespace std;
Scenario::Scenario(){
    description = "";
    stat = '\0';
    minStat = 0;
    choices = nullptr;
    next = nullptr;
}

Scenario::Scenario(string description,  string goodEnd, string badEnd, char stat, int minStat){
    description = description;
    goodEnd = goodEnd;
    badEnd = badEnd;
    stat = stat;
    choices = nullptr;
    next = nullptr;
}

void Scenario::printScene() const {
    cout << description << endl;
    cout << "Choices:" << endl;

    int i = 1;
    for (ChoiceNode* current = choices; current != nullptr; current = current->getNextChoice()) {
        cout << i << ". " << current->getChoice() << endl;
        i++;
    }
}

Scenario* Scenario::makeChoice(Character& player) {
    int choice;
    cout << "Enter your choice (1-" << minStat << "): ";
    cin >> choice;

    ChoiceNode* current = choices;
    for (int i = 1; i < choice; ++i) {
        if (current == nullptr) {
            cout << "Invalid choice. Try again." << endl;
            return nullptr;
        }
        current = current->getNextChoice();
    }

    // Validate if the choice meets the required stat
    if ((stat == 'a' && player.getAgility() >= minStat) ||
        (stat == 'c' && player.getCharisma() >= minStat) ||
        (stat == 'e' && player.getEndurance() >= minStat) ||
        (stat == 'i' && player.getIntelligence() >= minStat) ||
        (stat == 'l' && player.getLuck() >= minStat) ||
        (stat == 's' && player.getStrength() >= minStat) ||
        (stat == 'h' && player.getHealth() >= minStat)) {
        cout << "You have the required stat to proceed!" << endl;
    } else {
        cout << "You do not have the required stat to proceed. Try again." << endl;
        return nullptr;
    }

    return next;
}

void Scenario::addChoice(ChoiceNode* choiceNode, Scenario* nextScenario) {
    choiceNode->setNextChoice(choices);
    choices = choiceNode;
    next = nextScenario;
}