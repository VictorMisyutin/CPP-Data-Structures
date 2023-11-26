#include "ChoiceNode.h"

#include <string>

using namespace std;

ChoiceNode::ChoiceNode(string c, ChoiceNode* nextC){
    choice = c;
    nextChoice = nextC;
}

string ChoiceNode::getChoice(){
    return choice;
}

ChoiceNode* ChoiceNode::getNextChoice(){
    return nextChoice;
}

void ChoiceNode::setNextChoice(ChoiceNode* next) {
    nextChoice = next;
}
