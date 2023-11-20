#ifndef SCHEDULAR_H
#define SCHEDULAR_H

#include "PQType.h"

template <class ItemType>
class Scheduler: public PQType<ItemType>{
public:
    Scheduler(int s);
    int getNumJobs() const;
    void setCurrentJob(ItemType& j);
    void addJob(ItemType& j);
    void removeJob(ItemType& j);
private:
    int numJobs;
    ItemType currentJob;
};

#include "schedular_impl.tpp"

#endif /* SCHEDULAR_H */
