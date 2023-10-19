// Implementation file for sorted.h
#include <iostream>
#include "sorted.h"
using namespace std;

SortedType::SortedType()
{
  length = 0;
  info = new ItemType[MAX_ITEMS];
  currentPos = -1;
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
  int start = 0;
    int end = length - 1;
    int mid;
    found = false;

    while (start <= end) {
        mid = (start + end) / 2;
        switch (item.ComparedTo(info[mid])) {
            case LESS:
                end = mid - 1;
                break;
            case GREATER:
                start = mid + 1;
                break;
            case EQUAL:
                found = true;
                return info[mid];
        }
    }

    return item; 
}

void SortedType::DeleteItem(ItemType item) 
{
  int location = 0;

    while (item.ComparedTo(info[location]) != EQUAL) {
        location++;
    }

    for (int index = location + 1; index < length; index++) {
        info[index - 1] = info[index];
    }

    length--;
}

void SortedType::PutItem(ItemType item) 
{
      if (IsFull()) {
        // Resize the array if it's full
        int newCapacity = 2 * MAX_ITEMS;
        ItemType* newInfo = new ItemType[newCapacity];

        // Copy the elements to the new array
        for (int i = 0; i < length; i++) {
            newInfo[i] = info[i];
        }

        delete[] info;
        info = newInfo;
        MAX_ITEMS = newCapacity;
    }

    int location = 0;
    bool moreToSearch = (location < length);

    while (moreToSearch) {
        switch (item.ComparedTo(info[location])) {
            case LESS:
                moreToSearch = false;
                break;
            case GREATER:
                location++;
                moreToSearch = (location < length);
                break;
        }
    }

    for (int index = length; index > location; index--) {
        info[index] = info[index - 1];
    }

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
   for (int i = 0; i < length; i++) {
      info[i].Print(cout);
    }
    cout << endl;
}