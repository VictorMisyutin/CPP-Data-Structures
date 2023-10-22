#include "LinkedQueueType.h"
#include <iostream>
using namespace std;
LinkedQueueType::LinkedQueueType (){
    rear = nullptr;
    length = 0;   
}

LinkedQueueType::LinkedQueueType(const LinkedQueueType& qt){
    rear = nullptr;
	length = 0;
	NodeType* cur = qt.rear->next;
    
    int count = qt.length;
    while (count > 0){
        Enqueue(cur->info);
        cur = cur->next;
        count--;
    }
    
}

LinkedQueueType LinkedQueueType::operator=(const LinkedQueueType& rhs){
    if (this != &rhs) {
        MakeEmpty();
        rear = nullptr;
        length = 0;
        NodeType* cur = rhs.rear->next;
        NodeType* pre = nullptr;
        
        int count = rhs.length;
        while (count > 0){
            Enqueue(cur->info);
            pre = cur;
            cur = cur->next;
            count--;
        }
        rear = pre;
    }
    return *this;
}

LinkedQueueType::~LinkedQueueType (){
    length = 0;
}

void LinkedQueueType::MakeEmpty(){
    ItemType item;
	while (!IsEmpty()) {
        Dequeue(item); 
    }
}

bool LinkedQueueType::IsEmpty() const{
    return length == 0;
}

bool LinkedQueueType::IsFull() const{
    return false;
}

void LinkedQueueType::Enqueue(ItemType newItem){
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

void LinkedQueueType::Dequeue(ItemType& item){
    if (IsEmpty()) {
        throw EmptyQueue();
    }

    NodeType* front = rear->next;
    NodeType* newFront = front->next; 
    item = front->info;
    rear->next = newFront;  

    if(front != nullptr){
        delete front;
    }
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