#include <iostream>
#include "sorted.h"
#include "ItemType.h"
using namespace std;
int main() {
    SortedType classList;
    ItemType item1,item2,item3,item4,item5,item6;
    item1.Initialize(4);
    item2.Initialize(5);
    item3.Initialize(8);
    item4.Initialize(9);
    // item5.Initialize(3);
    // item6.Initialize(6);
    
    classList.PutItem(item1);
    classList.PutItem(item2);
    classList.PutItem(item3);
    classList.PutItem(item4);
    // classList.PutItem(item5);
    // classList.PutItem(item6);

    classList.Print();
    
    return 0;
}