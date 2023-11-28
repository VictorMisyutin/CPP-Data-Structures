#ifndef HASHTYPE_H
#define HASHTYPE_H
// File ItemType.h must be provided by the user of this class. 
//  ItemType.h must contain the following definitions: 
//  MAX_ITEMS:     the maximum number of items on the list 
//  ItemType:      generic data type
// Author: Ivan Temesvari
// Date 4/10/2019
#include <string>
#include <cmath>
#include <iostream>
#include <bitset>
using namespace std;
const int MAX_ITEMS = 11;
template<class ItemType>
class HashType
{
	public:
		HashType();
		// Constructor
		HashType(int s);
		//Dynamic size constructor
		void SetHashType(bool flag);
		void MakeEmpty();
		// Function: Returns the list to the empty state.
		// Post:  List is empty.
		bool IsFull() const;
		// Function:  Determines whether list is full.
		// Pre:  List has been initialized.
		// Post: Function value = (list is full)
		int GetNumItems() const;
		// Function: Determines the number of elements in list.
		// Pre:  List has been initialized.
		// Post: Function value = number of elements in list
		void RetrieveItem(ItemType item, bool& found);
		// Function: Retrieves list element whose key matches item's key (if
		//           present).
		// Pre:  List has been initialized.
		//       Key member of item is initialized.
		// Post: If there is an element someItem whose value matches
		//       item's value, then found = true and item contains the contents of
		//       the item if it is found.
		// 	     otherwise found = false and item is returned unchanged.
		//       List is unchanged.
		void InsertLinear(ItemType item, bool allowDuplicates);
		// Function: Adds item to list and uses a linear probing technique to
		// resolve collisions.  If the flag is true, a random hash method will be used.
		//If the flag is false, the division method will be used.
		// Pre:  List has been initialized.
		//       List is not full.
		//       item is not in list.
		// Post: item is in list.
		void InsertQuadratic(ItemType item, bool allowDuplicates);
		// Function: Adds item to list and uses a quadratic probing technique to
		// resolve collisions.  If the flag is true, a random hash method will be used.
		//If the flag is false, the division method will be used.
		// Pre:  List has been initialized.
		//       List is not full.
		//       item is not in list.
		// Post: item is in list.
		void DeleteItem(ItemType item);
		// Function: Deletes the element whose key matches item's key.
		// Pre:  List has been initialized.
		//       Key member of item is initialized.
		//       One and only one element in list has a key matching item's key.
		// Post: No element in list has a key matching item's key.
		int Hash(ItemType item) const;
		//This is the hash function for this class. If the flag is true, a random hash method will be used.
		//If the flag is false, the division method will be used.

		void setA(int newA);
		// set a to differente value

		unsigned long int GetCollisions() const;
		//return the number of collisions that occured during the build of the hash table
		template<class Item>
		friend ostream& operator<<(ostream& out, const HashType<Item>& items);

	private:
		int a; //the value used for a polynomial hash function. default is 33
		bool hashType;  //false is division method, true is a random folding method. default is false.
		unsigned long int numCollisions;
		int numItems;
		int size;
		ItemType* info;
		ItemType emptyItem;
};

template<class ItemType>
void HashType<ItemType>::SetHashType(bool flag){
	hashType = flag;
}

template<class ItemType>
HashType<ItemType>::HashType()
{
  a = 33;
  hashType = false;
  numCollisions = 0;
  numItems = 0;
  size = MAX_ITEMS;
  info = new ItemType[size];
  for(int i = 0; i < size; i++)
	  info[i] = emptyItem;
}

template<class ItemType>
HashType<ItemType>::HashType(int s){
	hashType = false;
	numItems = 0;
	numCollisions = 0;
	size = s;
	info = new ItemType[size];
	for(int i = 0; i < size; i++){
		info[i] = emptyItem;
	}
}

template<class ItemType>
bool HashType<ItemType>::IsFull() const
{
  return (numItems == size);
}

template<class ItemType>
int HashType<ItemType>::GetNumItems() const
{
  return numItems;
}

template<class ItemType>
void HashType<ItemType>::MakeEmpty()
// Post: list is empty.
{
  numItems = 0;
  for(int i = 0; i < size; i++)
	  info[i] = emptyItem;
}

//Updated IT via Dale 1/31/2019
template<class ItemType>
void HashType<ItemType>::DeleteItem(ItemType item)
{
	int location = 0;
	int startLoc;

	startLoc = Hash(item);
    location = startLoc;
    do
    {
      if (info[location] == item || info[location] == emptyItem){
    	  info[location] = -1;
    	  numItems--;
    	  return;
      }
      else
    	  location = (location + 1) % size;
    } while (location != startLoc);

    if(location == startLoc){
    	cout << "Item to delete not found." << endl;
    }
}

template<class ItemType>
int HashType<ItemType>::Hash(ItemType item) const
// Post: Returns an integer between 0 and MAX_ITEMS -1.
{
	int hash = 0;
    int n = item.length();
    for (int i = 0; i < n; i ++)
        hash = a * hash + item.at(i);
    return abs(hash);
}

template<class ItemType>
unsigned long int HashType<ItemType>::GetCollisions() const{
	return numCollisions;
}

template<class ItemType>
void HashType<ItemType>::setA(int newA){
	a = newA;
}


template<class ItemType>
void HashType<ItemType>::InsertLinear(ItemType item, bool allowDuplicates)
// Post: item is stored in the array at position item.Hash()
//       or the next free spot.
{
  int location = Hash(item) % size;

  while (info[location] != emptyItem){
	if(info[location] == item && !allowDuplicates){
		return;
	}
    location = (location + 1) % size;   //linear probing
    numCollisions++;
  }

  info[location] = item;
  numItems++;
}

template<class ItemType>
void HashType<ItemType>::InsertQuadratic(ItemType item, bool allowDuplicates)
{
    int location;
    int originalLocation;
    int i = 1;

    originalLocation = location = Hash(item) % size;

    while (info[location] != emptyItem)
    {
		if(info[location] == item && !allowDuplicates){
			return;
		}
        location = (originalLocation + i * i) % size; // quadratic probing
        i++;
        numCollisions++;
    }

    info[location] = item;
    numItems++;
}

template<class ItemType>
void HashType<ItemType>::RetrieveItem(ItemType item, bool& found)
{
  int location;
  int startLoc;
  bool moreToSearch = true;

  startLoc = Hash(item);
  location = startLoc;
  do
  {
    if (info[location] == item || info[location] == emptyItem)
      moreToSearch = false;
    else
      location = (location + 1) % size;
  } while (location != startLoc && moreToSearch);
  found = (info[location] == item);
  if (found)
    item = info[location];
}

template<class Item>
ostream& operator<<(ostream& out, const HashType<Item>& items){
	out << "[ ";
	for(int i = 0; i < items.numItems; i++){
		if(i == 0)
			out << items.info[i];
		else
			out << ", " << items.info[i];
	}
	out << " ]" << endl;
	return out;
}

#endif
