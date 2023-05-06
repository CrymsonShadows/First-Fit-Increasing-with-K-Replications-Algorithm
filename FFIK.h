#include "Task.h"
#include <vector>

int FFIK(std::vector<Task> &tasks, std::vector<std::vector<Task>> &processors, std::vector<double> &processors_u, int m_processors, int k_replicas){
    int tasks_assigned = 0;
    // sets done = 0, maxgroups = floor(m/k)
    // {0.1, 0.2, 0.35, 0.4, 0.45, 0.5, 0.5}
    int setsDone = 0;
    int maxGroups = m_processors/k_replicas;
    while(!tasks.empty() && setsDone != maxGroups){
        //for(int i = setsDone; i < maxGroups; i++){
            if(tasks.front().u + processors_u[setsDone*k_replicas] <= 1){
                ++tasks_assigned;
                for(int j = 0; j < k_replicas; j++){
                    processors_u[setsDone*k_replicas+j] += tasks.front().u;
                    processors[setsDone*k_replicas+j].push_back(tasks.front());
                }
                tasks.erase(tasks.begin());
            }
            else{
                ++setsDone;
                //break;
            }
        }
    //}

    return tasks_assigned;
}