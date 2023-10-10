#include <iostream>
#include "LinkedQueueType.h"
// #include "ItemType.h"
using namespace std;
int main() {
    LinkedQueueType q;
    q.Enqueue(ItemType(8));
    q.Enqueue(ItemType(6));
    q.Enqueue(ItemType(7));
    q.Enqueue(ItemType(5));
    q.Enqueue(ItemType(3));
    q.Enqueue(ItemType(0));
    q.Enqueue(ItemType(9));
    q.Print();
    ItemType item;
    q.Dequeue(item);
    cout << item << endl;
    q.Dequeue(item);
    cout << item << endl;
    q.Print();
    LinkedQueueType q2(q); //call copy constructor
    q2.Print();
    q2.Dequeue(item);
    cout << item << endl;
    q2.Print();
    LinkedQueueType q1;
    q1 = q; //call assignment operator=
    q1.Print();
    return 0;
}
// Expected output:
// 8 6 7 5 3 0 9
// 8
// 6
// 7 5 3 0 9
// 7 5 3 0 9
// 7
// 5 3 0 9
// 7 5 3 0 9