// Implementation file for Unsorted.h

#include "unsorted.h"
#include <iostream>

using namespace std;

UnsortedType::UnsortedType()
{
  length = 0;
}
bool UnsortedType::IsFull() const
{
  return (length == MAX_ITEMS);
}
int UnsortedType::GetLength() const
{
  return length;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been returned;
//       otherwise, item is returned. 
{
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < length);

  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    {
      case LESS    : 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
  return item;
}
void UnsortedType::MakeEmpty()
// Post: list is empty.
{
  length = 0;
}
void UnsortedType::PutItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
}
void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
// Post: No element in the list has a key that matches item's.
{
  // This function has a time complexity of O(N) because
  // the for loop iterates through each element in the list once.
  int deletedCount = 0;
  for (int i = 0 ; i< length;i++){
    if (item.ComparedTo(info[i]) == EQUAL){
      info[i] = info[length-1];
      deletedCount++;
      length--;
    }
  }
}
void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

ItemType UnsortedType::GetNextItem()
// Pre:  ResetList was called to initialized iteration.
//       No transformer has been executed since last call.
//       currentPos is defined.
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  return info[currentPos];
}

void UnsortedType::Print(){
  //Complete this.
  int length = GetLength();
  if (length > 0){
    ItemType current;
    while (length > 0){
      current = GetNextItem();
      current.Print(cout);
      length--;
    }
  }
  else{
    cout << "Empty." << endl;
  }
}

void UnsortedType::ShiftRight(){
  // This function also has a time complexity of O(N) because
  // the for loop iterates through each element in the list once.
  ItemType lastItem = info[length-1];
  for(int i = length-1 ; i>0;i--){
    info[i] = info[i-1];
  }
  info[0] = lastItem;
}
