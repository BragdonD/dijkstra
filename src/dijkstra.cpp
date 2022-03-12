/**
 * @file Dijkstra.cpp
 * @author DUCLOS Thomas - KEBE Ibrahim
 * @brief dijkstra algorithm's source file
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <algorithm>
#include "dijkstra.hpp"

/**
 * @brief Dijkstra algorithm, it goes through the graph and calcul the shortest distance between the 
 * starting peak and each peak. 
 * 
 * @param g Graph to apply dijkstra
 * @param start strating peak's id
 * @return std::vector<std::pair<Peak*, double>> 
 */
std::vector<std::pair<Peak*, double>> algo::dijkstra(Graph &g, int start) {
    /**
     * @brief Function to compare the distance between the peak and the first peak of two peaks. 
     * It it made for creating an heap 
     * 
     */
    auto compare_d = [](std::pair<Peak*, double>& a, std::pair<Peak*, double>& b) {
        if(a.second == -1) return true;
        if(b.second == -1) return false;
        return a.second > b.second;
    };
    ///Initialisation
    g.resetPeaks();
    std::vector<std::pair<Peak*, double>> v = initDijkstra(g.getPeaks(), start);
    std::vector<std::pair<Peak*,double>> r;
    std::make_heap(std::begin(v), std::end(v), compare_d);
    /**
     * @brief while each peak hasn't been marked as visited.
     * if a peak steal got an infinite value when he is on top of the heap it means that it is unreachable.
     * he is then poped.
     */
    while(!v.empty()) {
        ///Take the front of the heap
        std::pair<Peak*, double> s = v.front();
        std::pop_heap(std::begin(v), std::end(v), compare_d);
        v.pop_back();
        r.push_back(s);
        s.first->setMarking(marking::visited);
        ///Treat all his the heap front's successors
        for(auto &it : s.first->getSuccessors()) {
            int s1 = s.second;
            int s2 = it.second;
            int s2_dep = 0;
            ///get the distance between the successors and the starting heap
            for(auto &it2 : v) {
                if(it2.first->getNum() == it.first->getNum()) {
                    s2_dep = it2.second;
                    break;
                }
            }
            ///update the distance of the successors to the starting peak if a shorter path has been found
            if(s2_dep >= s1 + s2 || s2_dep == -1) {
                for(auto &it2 : v) {
                    if(it2.first->getNum() == it.first->getNum()) {
                        it2.second = s1 + s2;
                        it2.first->setPredecessor(s.first);
                        break;
                    }
                }
            }
        }
        ///Re-sort the heap
        std::make_heap(std::begin(v), std::end(v), compare_d);
    }
    return r;
}

/**
 * @brief Algorithm to get a initialized vector to use dijkstra algorithm.
 * It initialized all the distance to infinite except for teh starting peak which is put to 0.
 * 
 * @param v 
 * @param start 
 * @return std::vector<std::pair<Peak*, double>> 
 */
std::vector<std::pair<Peak*, double>> algo::initDijkstra(const std::vector<Peak*> &v, int start) {
    std::vector<std::pair<Peak*, double>> r;
    for(const auto &it : v) {
        if(it->getNum() == start) {
            r.push_back({it, 0});
        }
        else {
            r.push_back({it, -1});
        }
    }
    return r;
}

/**
 * @brief Algorithm to print Dijkstra algorithm result
 * 
 * @param r Dijkstra algorithm result
 */
void algo::printDijkstra(std::vector<std::pair<Peak*, double>>& r, int start) {
    for(const auto &it :r) {
        std::cout << "Peak : " << it.first->getNum() << " is at a distance of : " << it.second << " from peak " << start;
        if(it.first->getPredecessor() != NULL)
            std::cout << " and has for predecessor : " << it.first->getPredecessor()->getNum() << std::endl;
        else 
            std::cout << std::endl;
    }
}