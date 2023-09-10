#include "unsorted.h"
#include <iostream>
using namespace std;
int main(){
  // Create test array
  int testArray[14] = { 5, -12, 34, 34, 5, 45, 8, -6, 15, 40, 20, 2, 1, 12 };
  ItemType arrayList[14];
  UnsortedType linkedList, list1, list2;
  ItemType temp;

  // Create test linked list and array
  for (int i = 13; i >= 0; i--){
    temp.Initialize(testArray[i]);
    linkedList.PutItem(temp);
    arrayList[i] = temp; 
  }

  ItemType item;
  item.Initialize(8);
  
  // test split lists array
  cout << "---------- Array-Based ----------" << endl;
  UnsortedType::SplitLists(arrayList, 14,item, list1, list2);
  list1.Print();
  list2.Print();

  // clear lists
  list1.MakeEmpty();
  list2.MakeEmpty();  

  // test split lists linked list
  cout << "\n---------- Link-Based ----------" << endl;
  UnsortedType::SplitLists(linkedList, item, list1, list2);
  
  list1.Print();
  list2.Print();
}


