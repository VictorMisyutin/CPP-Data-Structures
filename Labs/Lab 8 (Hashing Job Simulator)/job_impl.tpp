#include "job.h"

Job::Job(){
    length = 0;
    priority = 0;
}

Job::Job(int p, int l){
    length = l;
    priority = p;
}

int Job::getLength() const{
    return length;
}

void Job::decrementLength(){
    length--;
}

int Job::getPriority() const{
    return priority;
}

// friend ostream& operator<<(ostream& out, const Job& j);
bool Job::operator<(Job otherJob){
    if(this->priority < otherJob.priority){
        return true;
    }
    else 
        return false;
}
bool Job::operator>(Job otherJob){
    if(this->priority > otherJob.priority){
        return true;
    }
    else 
        return false;
}
bool Job::operator==(Job otherJob){
    if(this->priority == otherJob.priority){
        return true;
    }
    else 
        return false;
}
bool Job::operator<=(Job otherJob){
    if(this->priority <=  otherJob.priority){
        return true;
    }
    else 
        return false;
}