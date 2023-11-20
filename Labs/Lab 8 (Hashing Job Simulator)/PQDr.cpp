#include "PQType.h"
#include "job.h"
#include "schedular.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {

    int MAX_CYCLES = 6675;
    int numCycles = 0;
    int numJobs = 0;
    int completedSims = 0;
    double jobsPerCycle = 0.0f;
    double totalJobsPerCycle = 0.0f;
    bool terminatedEarly = false;

    for(int i = 0; i < 1000 ; i++){
        PQType<Job> jobQueue(50);
        Scheduler<Job> scheduler(50);
        srand(time(0) + i);
        for (int i = 0; i < 50; i++) {
            int length = 1 + (rand() % 100);
            int priority = rand() % 2 == 1 ? 1 + (rand() % 20) : -1 * (rand() % 19);
            Job job(priority, length);
            jobQueue.Enqueue(job);
        }
        while (!jobQueue.IsEmpty()) {
            Job currentJob;
            jobQueue.Dequeue(currentJob);
            numCycles += currentJob.getLength();
            numJobs++;
            if(numCycles > MAX_CYCLES){
                terminatedEarly = true;
                break;
            }
            // cout << "Processing Job: Priority = " << currentJob.getPriority() 
            //         << ", Length = " << currentJob.getLength() << endl;
            scheduler.addJob(currentJob);
            numCycles += currentJob.getLength();
            jobsPerCycle = (jobsPerCycle + (scheduler.getNumJobs() / currentJob.getLength()))/2;
        }

        if(terminatedEarly){
            cout << "Average number of jobs in the heap per cycle: " << (int)(jobsPerCycle) << 
                    ".\nThe scheduler did not complete all 50 jobs.\nJobs processed: " << numJobs << "." << endl; 
        }
        else{
            completedSims++;
            cout << "Average number of jobs in the heap per cycle: " << (int)(jobsPerCycle) << 
                    ".\nThe scheduler completed all 50 jobs.\nIt took " << numCycles << " to complete them." << endl; 
        }
        numCycles = 0;
        numJobs = 0;
        terminatedEarly = false;
        jobQueue.MakeEmpty();
        scheduler.MakeEmpty();
        totalJobsPerCycle = (totalJobsPerCycle + jobsPerCycle)/2;
        jobsPerCycle = 0.0f;
    }
    cout << "Average number of jobs in heap per cycle: " << (int)(totalJobsPerCycle) << endl; 
    cout << "Completed Simulations: " << completedSims << endl;
    cout << "Incomplete Simulations: " << (1000 - completedSims) << endl;

   return 0;
}
