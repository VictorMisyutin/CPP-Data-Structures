#include <iostream>
#include <fstream>
#include "StackType.h"
#include "StackTypeArray.h"
using namespace std;
//Implement ReplaceItem and Identical here in the driver file.
// linked list functions
void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem){
//Function: Replaces all occurrences of oldItem with newItem.
//Precondition: stack has been initialized.
//Postcondition: Each occurrence of oldItem in stack has been replaced by newItem.
    
    //Create a new stack
    StackType tempStack;

    // copy over each item unless it is the old item, then copy over the new item
    while(!stack.IsEmpty()){
        ItemType item = stack.Top();
        stack.Pop();
        if(item == oldItem){
            tempStack.Push(newItem);
        }
        else{
            tempStack.Push(item);
        }
    }

    // copy over the corrected stack to the old stack
    while(!tempStack.IsEmpty()){
        stack.Push(tempStack.Top());
        tempStack.Pop();
    }
}

bool Identical(const StackType& stack1, const StackType& stack2){
//Function: Determines if two stacks are identical.
//Preconditions: stack1 and stack2 have been initialized.
//Postconditions: stack1 and stack2 are unchanged.
// Function return value = stack1 and stack2 are identical
    StackType temp1 = stack1;
    StackType temp2 = stack2;


    // compare each value and return false if not the same.
    while (!temp1.IsEmpty() && !temp2.IsEmpty()){
        if(temp1.Top() != temp2.Top())
            return false;
        temp1.Pop();
        temp2.Pop();
    }

    // reached the end without any differences in values
    return temp1.IsEmpty() && temp2.IsEmpty();
}

// array functions
void ReplaceItem(StackTypeArray& stack, ItemType oldItem, ItemType newItem) {
    StackTypeArray tempStack;  

    while (!stack.IsEmpty()) {
        ItemType current = stack.Top();
        stack.Pop();  

        if (current == oldItem) {
            tempStack.Push(newItem);
        } 
        else {
            tempStack.Push(current);
        }
    }

    // Transfer the modified items from the temporary stack back to the original stack
    while (!tempStack.IsEmpty()) {
        stack.Push(tempStack.Top());
        tempStack.Pop();
    }
}

bool Identical(const StackTypeArray& stack1, const StackTypeArray& stack2){
    if (stack1.IsEmpty() && stack2.IsEmpty()) {
        return true;
    } 
    else if (stack1.IsEmpty() || stack2.IsEmpty()) {
        return false;
    }

    StackTypeArray tempStack1(stack1);
    StackTypeArray tempStack2(stack2);

    while (!tempStack1.IsEmpty() && !tempStack2.IsEmpty()) {
        if (tempStack1.Top() != tempStack2.Top()) {
            return false;
        }
        tempStack1.Pop();
        tempStack2.Pop();
    }

    return tempStack1.IsEmpty() && tempStack2.IsEmpty();
}

int main()
{
    try{
        StackType stack;
        stack.Print();
        stack.Push(4);
        stack.Push(4);
        stack.Push(5);
        stack.Push(4);
        stack.Push(3);
        stack.Push(4);
        stack.Print();
        ReplaceItem(stack, 4, 8);
        stack.Print();
        StackType myStack;
        myStack.Print();
        myStack.Push(4);
        myStack.Push(4);
        myStack.Push(5);
        myStack.Push(4);
        myStack.Push(3);
        myStack.Push(4);
        myStack.Print();
        if(Identical(stack, myStack)){
            cout << "The stacks are identical." << endl;
        }
        else{
            cout << "The stacks are NOT identical." << endl;
        }

        cout << "\nHere is the same driver with the Array version" << endl;
        StackTypeArray stackArr;
        stackArr.Print();
        stackArr.Push(4);
        stackArr.Push(4);
        stackArr.Push(5);
        stackArr.Push(4);
        stackArr.Push(3);
        stackArr.Push(4);
        stackArr.Print();
        ReplaceItem(stackArr, 4, 8);
        stackArr.Print();
        StackTypeArray myStackArr;
        myStackArr.Print();
        myStackArr.Push(4);
        myStackArr.Push(4);
        myStackArr.Push(5);
        myStackArr.Push(4);
        myStackArr.Push(3);
        myStackArr.Push(4);
        myStackArr.Print();
        if(Identical(stackArr, myStackArr)){
            cout << "The stacks are identical." << endl;
        }
        else{
            cout << "The stacks are NOT identical." << endl;
        }
    }
    catch ( const FullStack& e )
    {
        cout << "Stack is full!" << endl;
    }
    catch(const EmptyStack& e){
        cout << "Stack is empty!" << endl;
    }
    return 0;
}