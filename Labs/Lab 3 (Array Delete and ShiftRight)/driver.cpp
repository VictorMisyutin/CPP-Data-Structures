#include <iostream>
#include "unsorted.h"
#include "ItemType.h"
using namespace std;
int main() {
    UnsortedType classList;
    ItemType item1,item2,item3,item4,item5;
    item1.Initialize(4);
    item2.Initialize(5);
    item3.Initialize(8);
    
    classList.PutItem(item1);
    classList.PutItem(item2);
    classList.PutItem(item1);
    classList.PutItem(item1);
    classList.PutItem(item3);
    cout << "(original) length: " << classList.GetLength() << endl;
    classList.ResetList();
    classList.Print();
    classList.ShiftRight();
    cout << "(shifted right) length: " << classList.GetLength() << endl;
    classList.ResetList();
    classList.Print();
    classList.DeleteItem(item1);
    classList.DeleteItem(item1);
     cout << "(delete all 4s) length: " << classList.GetLength() << endl;
     classList.ResetList();
     classList.Print();
     classList.ShiftRight();
     cout << "(shift right) length: " << classList.GetLength() << endl;
     classList.ResetList();
     classList.Print();
    return 0;
}