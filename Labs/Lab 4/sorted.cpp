#include "sorted.h" 
SortedType::SortedType(){
 length = 0;
 currentPos = -1;
 info = new ItemType[MAX_ITEMS];
}

void SortedType::MakeEmtpy(){
    length = 0;
}
// Function: Returns list to the empty state
// Post:  List is empty.

bool SortedType::IsFull() const{
    return (length == MAX_ITEMS);
}
// Function:  Determines whether list is full.
// Pre:  List has been initialized.
// Post: Function value = (list is full)

int SortedType::GetLength() const{
    return length;
}
// Function: Determines the number of elements in list.
// Pre:  List has been initialized.
// Post: Function value = number of elements in list

ItemType SortedType::GetItem(ItemType item, bool& found){
    ItemType searchItem = new ItemType;
    for(int i = 0; i < length; i++){
        if(info[i].ComparedTo(item) == EQUAL){
            found = true;
            return info[i];
        }
    }
    found = false;
    return item;
}
// Function: Retrieves list element whose key matches item's key (if
//           present).
// Pre:  List has been initialized.
//       Key member of item is initialized.
// Post: If there is an element someItem whose key matches
//       item's key, then found = true and item is returned;
//       someItem; otherwise found = false and item is returned.
//       List is unchanged.

void SortedType::PutItem(ItemType item){
    if(length = 0){
        info[0] == item;
    }
    else{
        if(IsFull()){
            ItemType temp = ItemType[length*2];
            for (int i = 0; i < length;i++){
                temp[i] = info[i];
            }
            MakeEmpty();
            info= temp;
        }
        for (int i = length - 1; (i >= 0 && info[i].ComparedTo(item) == GREATER); i--) 
            info[i + 1] = info[i]; 
    
        info[i + 1] = item; 
    }
    length++;
}
// Function: Adds item to list.
// Pre:  List has been initialized.
//       List is not full.
//       item is not in list.
//       List is sorted.
// Post: item is in list.
//       List is sorted

void SortedType::DeleteItem(ItemType item){

}
// Function: Deletes the element whose key matches item's key.
// Pre:  List has been initialized.
//       Key member of item is initialized.
//       One and only one element in list has a key matching item's key.
// Post: No element in list has a key matching item's key.
//       List is sorted.

void SortedType::ResetList(){
    currentPos = -1;
}
// Function: Initializes current position for an iteration through the list.
// Pre:  List has been initialized.
// Post: Current position is prior to list.

ItemType SortedType::GetNextItem(){

}
// Function: Gets the next element in list.
// Pre:  List has been initialized and has not been changed since last call.
//       Current position is defined.
//       Element at current position is not last in list.
//	     
// Post: Current position is updated to next position.
//       Returns a copy of element at current position.

void SortedType::MakeEmpty(){

}
// Function: Make the list empty
// Pre:  List has been initialized.
// Post: The list is empty

void SortedType::Print(){

}