// Implementation file for sorted.h
#include <iostream>
#include "sorted.h"
using namespace std;

SortedType::SortedType()
{
  length = 0;
}

void SortedType::MakeEmpty() 
{
  length = 0;
} 


bool SortedType::IsFull() const
{
  return (length == MAX_ITEMS);
}

int SortedType::GetLength() const
{
  return length;
}

ItemType SortedType::GetItem(ItemType item, bool& found) 
{
  int midPoint;
  int first = 0;
  int last = length - 1;

  bool moreToSearch = first <= last;
  found = false;
  while (moreToSearch && !found) 
  {
    midPoint = ( first + last) / 2;
    switch (item.ComparedTo(info[midPoint])) 
    {
      case LESS    : last = midPoint - 1;
                     moreToSearch = first <= last;
                     break;
      case GREATER : first = midPoint + 1;
                     moreToSearch = first <= last;
                     break;
      case EQUAL   : found = true;
                     item = info[midPoint];
                     break;
    }
  }
  return item;
}

void SortedType::DeleteItem(ItemType item) 
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;
  for (int index = location + 1; index < length; index++)
    info[index - 1] = info[index];
  length--;
}

void SortedType::PutItem(ItemType item) 
{
  bool moreToSearch;
  int location = 0;

  if(length == MAX_ITEMS - 1 ){
    MAX_ITEMS = MAX_ITEMS*2;
  }
  moreToSearch = (location < length);
  while (moreToSearch) 
  {
    switch (item.ComparedTo(info[location])) 
    {
      case LESS    : moreToSearch = false;
                     break;
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
    } 
  } 
  for (int index = length; index > location; index--)
    info[index] = info[index - 1];
  info[location] = item;
  length++;
}

void SortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

ItemType SortedType::GetNextItem()
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  return info[currentPos];
}

void SortedType::Print(){
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