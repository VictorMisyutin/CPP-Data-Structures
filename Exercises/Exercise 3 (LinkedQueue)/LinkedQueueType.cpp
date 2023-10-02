#include "LinkedQueueType.h"
#include <iostream>
using namespace std;

struct NodeType
{
    ItemType info;
    NodeType* next;
};

LinkedQueueType::LinkedQueueType(){
    length = 0;
    rear = nullptr;
    front = nullptr;
}
// Class constructor.
// Because there is a default constructor, the precondition
// that the queue has been initialized is omitted.
LinkedQueueType::LinkedQueueType(const LinkedQueueType& qt){
    // same as constructor
    length = 0;
    rear = nullptr;
    front = nullptr;
    // iteratate through other queue and copy over each node
    NodeType* currentQT = qt.front;
    while (currentQT != nullptr){
        NodeType* newNode = new NodeType;
        newNode->info = currentQT->info;
        newNode->next = nullptr;
        if(rear == nullptr){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        currentQT = currentQT->next;
        length++;
    }
}

//Copy Constructor
LinkedQueueType& LinkedQueueType::operator=(const LinkedQueueType& rhs){
    // clear queue
    MakeEmpty();

    // copy over other queue, similar to previous function
    NodeType* currentRHS = rhs.front;
    while (currentRHS != nullptr){
        NodeType* newNode = new NodeType;
        newNode->info = currentRHS->info;
        newNode->next = nullptr;
        if(rear == nullptr){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        currentRHS = currentRHS->next;
        length++;
    }
    return *this;
}

//Overloaded assignment operator=
LinkedQueueType::~LinkedQueueType (){
    // delete each node in the queue
    NodeType* current = front;
    while(current != nullptr){
       NodeType* temp = current;
       current = current->next;
       delete temp;
    }
    // delete pointers to front and rear of queue
    length = 0;
    delete rear;
    delete front;
}

// Class destructor.
void LinkedQueueType::MakeEmpty(){
    length = 0;
    front = 0;
    rear = 0;
}
// Function: Initializes the queue to an empty state.
// Post: Queue is empty.
bool LinkedQueueType::IsEmpty() const{
    return (length==0);
}
// Function: Determines whether the queue is empty.
// Post: Function value = (queue is empty)
bool LinkedQueueType::IsFull() const{
    return(length == MAX_ITEMS);
}
// Function: Determines whether the queue is full.
// Post: Function value = (queue is full)
void LinkedQueueType::Enqueue(const ItemType& newItem){
    // create new node with the new item
    NodeType* newNode = new NodeType;
    newNode->info = newItem;
    // since node is at the rear it does not point to anything
    newNode->next = nullptr;
    if(length == 0){
        // if this is the only node so far then front and end are the same
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    length++;
}
// Function: Adds newItem to the rear of the queue.
// Post: newItem is at rear of queue.
void LinkedQueueType::Dequeue(ItemType& item){ 
  
  if (length != 0){
    item = front->info;
    
    NodeType* temp = front;
    front = temp->next;     
    delete temp;
    length--;
  }
  else {
    throw EmptyQueue();
  }
}
// Function: Removes front item from the queue and returns it in
// item.
// Post: If (queue is empty) EmptyQueue exception is thrown
// and item is undefined
// else front element has been removed from queue and
// item is a copy of removed element.

void LinkedQueueType::Print(){
    // itterate through each node and print the info in that node
    NodeType* current = front;
    while (current != nullptr){
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
} 
//Print function