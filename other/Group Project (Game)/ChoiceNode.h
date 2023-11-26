#ifndef CHOICENODE_H
#define CHOICENODE_H

#include <iostream>
#include <string>
using namespace std;
class ChoiceNode {
public:
    ChoiceNode(string c, ChoiceNode* nextC);

    string getChoice();

    ChoiceNode* getNextChoice();

    void setNextChoice(ChoiceNode* next);

private:
    string choice;
    ChoiceNode* nextChoice;
};

#include "ChoiceNode_impl.tpp"

#endif