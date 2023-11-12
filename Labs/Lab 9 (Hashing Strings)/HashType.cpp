#include "HashType.h"

template<class ItemType>
HashType<ItemType>::HashType()
{
  numCollisions = 0;
  numItems = 0;
  size = MAX_ITEMS;
  info = new int[size];
  for(int i = 0; i < size; i++)
	  info[i] = emptyItem;
}
// Constructor
template<class ItemType>
HashType<ItemType>::HashType(int s, int factor){
	numItems = 0;
	numCollisions = 0;
	size = s;
	info = new int[size];
	for(int i = 0; i < size; i++){
		info[i] = emptyItem;
	}
}
//Dynamic size constructor
void MakeEmpty();
// Function: Returns the list to the empty state.
// Post: List is empty.
template<class ItemType>
bool HashType<ItemType>::IsFull() const
{
  return (numItems == size);
}
// Function: Determines whether list is full.
// Pre: List has been initialized.
// Post: Function value = (list is full)
template<class ItemType>
int HashType<ItemType>::GetNumItems() const
{
  return numItems;
}
// Function: Determines the number of elements in list.
// Pre: List has been initialized.
// Post: Function value = number of elements in list
template<class ItemType>
void HashType<ItemType>::RetrieveItem(ItemType& item, bool& found)
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
// Function: Retrieves list element whose key matches item's key (if
// present).
// Pre: List has been initialized.
// Key member of item is initialized.
// Post: If there is an element someItem whose value matches
// item's value, then found = true and item contains the contents
// of the item if it is found.
// otherwise found = false and item is returned unchanged.
// List is unchanged.
template<class ItemType>
void HashType<ItemType>::InsertItemLinear(ItemType item){

}
// Function: Adds item to list and uses a linear probing technique to
// resolve collisions.
// Pre: List has been initialized.
// List is not full.
// item is not in list.
// Post: item is in list.
template<class ItemType>
void HashType<ItemType>::InsertItemQuadratic(ItemType item){

}
// Function: Adds item to list and uses a quadratic probing technique to
// resolve collisions.
// Pre: List has been initialized.
// List is not full.
// item is not in list.
// Post: item is in list.
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
// Function: Deletes the element whose key matches item's key.
// Pre: List has been initialized.
// Key member of item is initialized.
// One and only one element in list has a key matching item's key.
// Post: No element in list has a key matching item's key.
template<class ItemType>
int HashType<ItemType>::Hash(string item) const{
    int hash = 0;
    int n = item.length();
    for (int i = 0; i < n; i ++)
        hash = a * hash + item.at(i);  
    return hash;
}
//This is the hash function for this class
template<class ItemType>
unsigned long int HashType<ItemType>::GetCollisions() const{
    return numCollisions;
}
//return the number of collisions that occured during the build of
// the hash table
template<class ItemType>
	ostream& operator<<(ostream& out, const HashType<ItemType>& items){
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