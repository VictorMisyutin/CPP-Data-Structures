#include "schedular.h"

template <class ItemType>
Scheduler<ItemType>::Scheduler(int size) : PQType<ItemType>(size){
    numJobs = 0;
}
int Scheduler<ItemType>::getNumJobs() : PQType<ItemType>(size) const{
    return numJobs;
}

void Scheduler<ItemType>::setCurrentJob(ItemType& j) : PQType<ItemType>(size){
    currentJob = j;
}

void Scheduler<ItemType>::addJob(ItemType& j) : PQType<ItemType>(size){
    numJobs++;
    currentJob = j;
}
void Scheduler<ItemType>::removeJob(ItemType& j) : PQType<ItemType>(size){
    numJobs--;
    currentJob = nullptr;
}