// The function definitions for class StackTypeArray.
#include "StackTypeArray.h"
#include <iostream>
using namespace std;

StackTypeArray::StackTypeArray(int max)
{
  maxStack = max;
  top = -1;
  items = new ItemType[maxStack];
}


StackTypeArray::StackTypeArray()
{
  maxStack = 500;
  top = -1;
  items = new ItemType[maxStack];
}

bool StackTypeArray::IsEmpty() const
{
  return (top == -1);
}


bool StackTypeArray::IsFull() const
{
  return (top == maxStack-1);
}


void StackTypeArray::Push(ItemType newItem) 
{
  if (IsFull())
    throw FullStack();
  top++;
  items[top] = newItem;
}


void StackTypeArray::Pop()
{
  if( IsEmpty() )
    throw EmptyStack();
  top--;
}


ItemType StackTypeArray::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}    


StackTypeArray::~StackTypeArray()
{
  delete [] items;
}

void StackTypeArray::Print(){
  if (IsEmpty()) {
        cout << "" << endl;
    } 
    else {
        for (int i = top; i >= 0; i--) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
}

