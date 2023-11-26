#ifndef SCENARIO_H
#define SCENARIO_H

#include "ChoiceNode.h"
#include <string>
#include <iostream>
using namespace std;

class Scenario
{
public:
    Scenario();
    Scenario(string description, string goodEnd, string badEnd, char stat, int minStat);

    void printScene() const;
    Scenario* makeChoice(Character& player);
    void addChoice(ChoiceNode* choiceNode, Scenario* nextScenario);

private:
    char stat;
    int minStat;
    string description;
    string goodEnd;
    string badEnd;
    ChoiceNode* choices;
    Scenario* next;
};

#include "Scenario_impl.tpp"

#endif
