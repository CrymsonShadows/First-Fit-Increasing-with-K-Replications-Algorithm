#include <iostream>
#include <fstream>
#include <vector>
#include "FFIK.h"

void displayProcessorTasks(std::vector<std::vector<Task>> &processors){
    // for(auto processor : processors){
    //     for(auto task : processor){
    //         std::cout << task.toString() << " ";
    //     }
    //     std::cout << std::endl;
    // }

    for(int i = 0; i < processors.size(); i++){
        for(int k = 0; k < processors[i].size(); k++){
            std::cout << "Proccesor " << i << " " << processors[i][k].toString() << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    int numTasks;
    std::ifstream ifile("TaskList.txt");
    ifile >> numTasks;
    std::vector<Task> tasks(numTasks);
    int executionTime, period;
    double utilization;

    for(int i = 0; i < numTasks; i++){
        ifile >> executionTime >> period >> utilization;
        tasks[i] = Task(executionTime, period, utilization);
    }

    ifile.close();

    int k = 4;

    int m = 60;
    // std::vector<Task> unassignedTask(tasks);
    // std::vector<std::vector<Task>> processors(m, std::vector<Task>(0));
    // std::vector<double> processors_u(m);

    int tasksAssigned = 0;
    // tasksAssigned = FFIK(tasks, processors, processors_u, m, k);

    std::ofstream ofile("4_replicas_schedule.txt");
    ofile << "processors\ttasks assigned" << std::endl;

    for(m = 10; m <= 1000; m += 10){
        std::vector<Task> unassignedTask(tasks);
        std::vector<std::vector<Task>> processors(m, std::vector<Task>(0));
        std::vector<double> processors_u(m);
        tasksAssigned = FFIK(unassignedTask, processors, processors_u, m, k);
        ofile << m << "\t" << tasksAssigned << std::endl;
    }

    ofile.close();
    
    // std::cout << "Tasks assigned: " << tasksAssigned << std::endl;
    // displayProcessorTasks(processors);

    return 0;
}