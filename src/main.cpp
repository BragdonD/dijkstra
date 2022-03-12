/**
 * @file main.cpp
 * @author DUCLOS Thomas - KEBE Ibrahim
 * @brief Main file to use dijkstra algorithm
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "graph.hpp"
#include "dijkstra.hpp"

int main(int argc, char const *argv[])
{
    Graph g("graph.txt");
    int start = 1;

    ///Use dijkstra algorithm
    std::vector<std::pair<Peak*,double>> r = algo::dijkstra(g, start);

    ///Print dijkstra result
    algo::printDijkstra(r, start);
    
    return 0;
}
