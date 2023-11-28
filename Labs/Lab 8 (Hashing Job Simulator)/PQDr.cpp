#include "PQType.h"
#include "job.h"
#include "schedular.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isNumeric(string str) {
    for (int i = 0; (unsigned)i < str.length(); i++){
        if (isdigit(str[i]) == false)
            return false;
    }
        return true;
}

int main() {
    std::string userIn;
    do{
        cout << "How many cycles should the simulator run per simultation (Default: 2700)\nCheck MyFindins.txt file for more info.\nNumber of Cycles (enter a number): ";
        cin >> userIn;
    } while(!isNumeric(userIn));
    cout << endl;
    const int NUM_SIMULATIONS = 1000;
    const int TOTAL_CYCLES = stoi(userIn);
    const int INTERARRIVAL_TIME = 20;
    srand(time(0));

    int completedSimulations = 0;
    int incompleteSimulations = 0;

    for (int sim = 0; sim < NUM_SIMULATIONS; ++sim) {
        PQType<Job> jobQueue(50);
        Scheduler<Job> scheduler(50);

        int cycles = 0;
        int jobsProcessed = 0;
        float jobsPerCycle = 0.0;
        while (cycles < TOTAL_CYCLES) {
            jobsPerCycle += scheduler.getNumJobs();
            if(jobsProcessed >= 50){
                break;
            }
            Job currentJob;
            if (!scheduler.IsEmpty()) {
                scheduler.Dequeue(currentJob);
                jobsProcessed++;
                cycles += currentJob.getLength();
            }
            if (cycles % INTERARRIVAL_TIME == 0) {
                int length = 1 + (rand() % 100);
                int priority = rand() % 40 - 19;
                Job newJob(priority, length);
                jobQueue.Enqueue(newJob);
            }
            if (!jobQueue.IsEmpty()) {
                Job nextJob;
                jobQueue.Dequeue(nextJob);
                scheduler.addJob(nextJob);
            }
            cycles++;
        }

        cout << "Average number of jobs in the heap per cycle: " << jobsPerCycle / TOTAL_CYCLES << endl;

        if (jobsProcessed >= 50) {
            cout << "The scheduler completed all 50 jobs." << endl;
            cout << "It took " << cycles << " cycles to complete them." << endl;
            completedSimulations++;
        } else {
            cout << "The scheduler did not complete all 50 jobs." << endl;
            cout << "Jobs processed: " << jobsProcessed << endl;
            incompleteSimulations++;
        }
        cout << "-------" << endl;
    }

    cout << "Completed simulations: " << completedSimulations << endl;
    cout << "Incomplete simulations: " << incompleteSimulations << endl;
        
   return 0;
}
