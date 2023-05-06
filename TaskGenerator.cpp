#include <random>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Task.h"

int main()
{
    std::mt19937 rng(34); // create a random number engine with seed value 34
    std::uniform_int_distribution<int> dist(1, 100); // create a distribution to generate integers between 1 and 10

    int n = 1000;
    std::vector<Task> tasks(n);

    for(int i = 0; i < n; i++){
        int t = dist(rng);
        std::uniform_int_distribution<int> pDist(t,100);
        tasks[i] = Task(t,pDist(rng));
    }

    std::sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b) { return a.u < b.u; });

    std::ofstream ofile("TaskList.txt");

    ofile << n << std::endl;

    for(auto task : tasks){
        ofile << task.toString() << std::endl;
    }

    ofile.close();
    
    return 0;
}
