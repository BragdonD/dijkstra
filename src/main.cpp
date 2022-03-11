#include <iostream>
#include "graph.hpp"
#include "dijkstra.hpp"

int main(int argc, char const *argv[])
{
    Graph g("graph.txt");
    int start = 1;

    std::vector<std::pair<Peak*,double>> r = algo::dijkstra(g, start);

    for(const auto &it :r) {
        std::cout << "Peak : " << it.first->getNum() << " is at a distance of : " << it.second << " from peak " << start;
        if(it.first->getPredecessor() != NULL)
            std::cout << " and has for predecessor : " << it.first->getPredecessor()->getNum() << std::endl;
        else 
            std::cout << std::endl;
    }
    
    return 0;
}
