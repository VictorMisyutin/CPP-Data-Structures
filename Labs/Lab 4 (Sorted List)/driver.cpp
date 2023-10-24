#include "sorted.h"
#include <iostream>

using namespace std;


// ANSWERS TO THE QUESTIONS IN THE LAB
// ------------------------------------
// What is the time complexity of the unbounded potential of the class and why?
//     The time complexity of the SortedType class is O(N) because if the 
//     array becomes full, we need to copy over all of the elements from the 
//     full array to a new array.
// 
// With respect to an array implementation, how would you improve or change the approach of doubling
// the size of the array? Why do you think this approach is better? What are the drawbacks?
//     One thing that I would change about the array implementation of the SortedType class is
//     change the amount by which the array increases. Instead of doubling the size of the array 
//     each time it gets to big I would change the arrays size by a constant amount each time. Or I 
//     change the size from 2 times the current size to something like 1.5 the current when it gets 
//     to a certain size and then 1.3 when it reaches a higher size and so on. The reason I would do this
//     is because in the current approach, we are allocating a huge amount of memory at large values of N,
//     and if we dont intend to use all of it then we are wasting a lot of memory. However, in my approach,
//     a drawback is that we would be copying over the old array more often which would slow down the program.

int main(){
    SortedType sortedList;

    ItemType item1,item2,item3,item4,item5;
    item1.Initialize(5);
    item2.Initialize(2);
    item3.Initialize(8);
    item4.Initialize(1);
    item5.Initialize(7);

    sortedList.PutItem(item1);
    sortedList.PutItem(item2);
    sortedList.PutItem(item3);
    sortedList.PutItem(item4);
    sortedList.PutItem(item5);

    cout << "Initial List: " << endl;
    cout << "Length: " << to_string(sortedList.GetLength()) << endl;
    cout << "Size: " << sortedList.GetSize() << endl;
    for (int i = 0; i < sortedList.GetLength(); i++) {
        sortedList.GetNextItem().Print(cout); cout << " ";
    }
    cout << endl;
    cout << endl;

    sortedList.ResetList();
    ItemType item6,item7,item8;
    item6.Initialize(10);
    item7.Initialize(3);
    item8.Initialize(9);
    sortedList.PutItem(item6);
    sortedList.PutItem(item7);
    sortedList.PutItem(item8);

    cout << "List After Resizing: " << endl;
    cout << "Length: " << to_string(sortedList.GetLength()) << endl;
    cout << "Size: " << sortedList.GetSize() << endl;

    for (int i = 0; i < sortedList.GetLength(); i++) {
        sortedList.GetNextItem().Print(cout); cout << " ";
    }
    cout << endl;

    return 0;
}