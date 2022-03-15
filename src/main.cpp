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
#include "cli.hpp"

int main(int argc, char const *argv[])
{
    Graph g("test_infinite.txt");

    std::cout << "Write starting peak's id : " << std::endl;
    int start = cli::getInteger();
    
    ///Use dijkstra algorithm
    std::vector<std::pair<Peak*,double>> r = algo::dijkstra(g, start);

    ///Print dijkstra result for every path
    algo::printDijkstra(r, start);

    std::cout << "Write ending peak's id : " << std::endl;
    int end = cli::getInteger();
    ///Print dijkstra result for a unique path
    algo::printDijkstraShortestPath(r, start, end);

    return 0;
}
