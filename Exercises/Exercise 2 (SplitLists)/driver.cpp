#include "unsorted.h"
#include <iostream>
using namespace std;
int main(){
  int testArray[14] = { 5, -12, 34, 34, 5, 45, 8, -6, 15, 40, 20, 2, 1, 12 };
  UnsortedType list, list1, list2;
  for (int i = 13; i >= 0; i--){
    list.PutItem(testArray[i]);
  }

  ItemType item;
  item.Initialize(8);

   list.SplitListsArray(item, list1, list2);

  list1.Print();
  list2.Print();
}


