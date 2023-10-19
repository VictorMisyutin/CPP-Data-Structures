#include <iostream>
#include "unsorted.h"
using namespace std;

int main(){
    int count = 4;
    if (count < 10)
        cout << count;
    else
        cout << "count is equal to 10" << endl; 
    return 0;

}

// int main(){
//     UnsortedType list1;
//     list1.PutItem(ItemType(8));
//     list1.PutItem(ItemType(5));
//     list1.PutItem(ItemType(2));
//     list1.PutItem(ItemType(5));
//     list1.PutItem(ItemType(7));
//     list1.PutItem(ItemType(3));
//     list1.PutItem(ItemType(5));
//     list1.Print();
//     UnsortedType list2(list1);
//     list2.Print();
//     UnsortedType list3 = list1 + list2;
//     list3.Print();
//     // 13 8 9 10 9 8 13
//     return 0;
// }

// // EXPECTED OUTPUT:
// // 8 5 2 5 7 3 5 8 5 2 5 7 3 5
// // 8 5 2 5 7 3 5 8 5 2 5 7 3 5