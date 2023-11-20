#include "schedular.h"

template <class ItemType>
Scheduler<ItemType>::Scheduler(int size) : PQType<ItemType>(size){
    numJobs = 0;
}
template <class ItemType>
int Scheduler<ItemType>::getNumJobs() const{
    return numJobs;
}

template <class ItemType>
void Scheduler<ItemType>::setCurrentJob(ItemType& j){
    currentJob = j;
}

template <class ItemType>
void Scheduler<ItemType>::addJob(ItemType& j){
    numJobs++;
    currentJob = j;
    PQType<ItemType>::Enqueue(j);
}

template <class ItemType>
void Scheduler<ItemType>::removeJob(ItemType& j) {
    numJobs--;
    currentJob = nullptr;
    PQType<ItemType>::Dequeue(j);
}
