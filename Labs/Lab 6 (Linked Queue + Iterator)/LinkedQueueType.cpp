#include "LinkedQueueType.h"
#include <iostream>
using namespace std;

LinkedQueueType::LinkedQueueType(const LinkedQueueType& qt){
	// copy constructor
	rear = nullptr;
	length = 0;
	NodeType* cur = qt.rear;
    NodeType* pre = nullptr;
    
    while (cur != nullptr) {
        Enqueue(cur->info);
        pre = cur;
        cur = cur->next;
    }

    if (pre != nullptr) {
        rear = pre;
    }
}

LinkedQueueType LinkedQueueType::operator=(const LinkedQueueType& rhs){
	//assignment operator=
	LinkedQueueType(rhs);
    // if (this != &rhs) {
    //     MakeEmpty();
        
    //     NodeType* cur = rhs.rear;
    //     NodeType* pre = nullptr;
    //     while (cur != nullptr) {
    //         Enqueue(cur->info);
    //         pre = cur;
    //         cur = cur->next;
    //     }

    //     if (pre != nullptr) {
    //         rear = pre;
    //     }
    // }
    // return *this;
}

LinkedQueueType::LinkedQueueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
	rear = nullptr;
	length = 0;
}
LinkedQueueType::~LinkedQueueType()         // Class destructor
{
	MakeEmpty();
}

void LinkedQueueType::MakeEmpty()
// Post: rear and length have been reset to the empty state.
{
	ItemType item;
	while (!IsEmpty()) {
        Dequeue(item); 
    }
}

bool LinkedQueueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (length == 0);
}

bool LinkedQueueType::IsFull() const
// This structure can net get full.
{
  return false;
}

void LinkedQueueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue; newItem's next is front
//       otherwise a FullQueue exception is thrown.  
{
	NodeType* newNode = new NodeType;
    newNode->info = newItem;
    newNode->next = nullptr;

    if (IsEmpty())
    {
        rear = newNode;
        rear->next = newNode; 
    }
    else
    {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }

    length++;
}

void LinkedQueueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
	if(IsEmpty()){

	}
	NodeType* front = rear->next;
	NodeType* newFront;
	if(front->next != nullptr){
		newFront = front->next;
	}
	else{
		newFront = nullptr;
	}
	item = front->info;
	rear->next = newFront;
	delete front;
	length--;
}

void LinkedQueueType::Print(){
	NodeType* node = rear->next;
	int count = 0;
	while(count < length){
		cout << node->info << " ";
		node = node->next;
		count++;
	}
	cout << endl;
}

//
// The methods below provide the range-based for loop support. These would
// be customized with the companion LinkedQueueTypeIterator class that is returned.
//
LinkedQueueTypeIterator LinkedQueueType::begin()
{
	//Complete this.
	return LinkedQueueTypeIterator( rear != nullptr? rear->next: nullptr, 0);
	// return LinkedQueueTypeIterator(rear->next,0);
}

LinkedQueueTypeIterator LinkedQueueType::end()
{
	//Complete this.
	return LinkedQueueTypeIterator(nullptr, length);
}
