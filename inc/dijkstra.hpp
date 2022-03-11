#if !defined(DIJKSTRA_HPP)
#define DIJKSTRA_HPP

#include <vector>
#include "graph.hpp"
#include "peak.hpp"

namespace algo {
    std::vector<std::pair<Peak*, double>> dijkstra(Graph &g, int start);
    std::vector<std::pair<Peak*, double>> initDijkstra(const std::vector<Peak*> &v, int start);
}

#endif // DIJKSTRA_HPP
