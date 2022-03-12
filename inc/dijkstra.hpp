/**
 * @file dijkstra.hpp
 * @author DUCLOS Thomas - KEBE Ibrahim
 * @brief dijkstra algorithm's header file
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#if !defined(DIJKSTRA_HPP)
#define DIJKSTRA_HPP

#include <vector>
#include "graph.hpp"
#include "peak.hpp"

namespace algo {
    std::vector<std::pair<Peak*, double>> dijkstra(Graph &g, int start);
    std::vector<std::pair<Peak*, double>> initDijkstra(const std::vector<Peak*> &v, int start);
    void printDijkstra(std::vector<std::pair<Peak*, double>>& r, int start);
}

#endif // DIJKSTRA_HPP
