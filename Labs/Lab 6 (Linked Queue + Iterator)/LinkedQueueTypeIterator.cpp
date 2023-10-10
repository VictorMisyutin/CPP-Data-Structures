/*
 * LinkedQueueTypeIterator.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: igt88
 */
///////////////////////////////////////////////////////////////////////////////
//
// IMPLEMENTATION
//
///////////////////////////////////////////////////////////////////////////////
#include "LinkedQueueTypeIterator.h"
LinkedQueueTypeIterator::LinkedQueueTypeIterator(NodeType* start, int loc)
{
	//Complete this.
	item = start;
	location = loc;
}

ItemType& LinkedQueueTypeIterator::operator*()
{
	if(item == nullptr){
		static ItemType tempItem;
		return (tempItem);
	}
	else
		return (item->info);
}

LinkedQueueTypeIterator& LinkedQueueTypeIterator::operator++()
{
	if (item != nullptr){
		item = item->next;
		location++;
	}
	return *this;
}

bool LinkedQueueTypeIterator::operator!=(const LinkedQueueTypeIterator &it) const
{
	return (location != it.location);
}



