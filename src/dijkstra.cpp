#include <algorithm>
#include "dijkstra.hpp"

std::vector<std::pair<Peak*, double>> algo::dijkstra(Graph &g, int start) {
    auto compare_d = [](std::pair<Peak*, double>& a, std::pair<Peak*, double>& b) {
        if(a.second == -1) return true;
        if(b.second == -1) return false;
        return a.second > b.second;
    };

    g.resetPeaks();
    std::vector<std::pair<Peak*, double>> v = initDijkstra(g.getPeaks(), start);
    std::vector<std::pair<Peak*,double>> r;
    std::make_heap(std::begin(v), std::end(v), compare_d);

    while(!v.empty()) {
        std::pair<Peak*, double> s = v.front();
        std::pop_heap(std::begin(v), std::end(v), compare_d);
        v.pop_back();
        r.push_back(s);

        for(auto &it : s.first->getSuccessors()) {
            int s1 = s.second;
            int s2 = it.second;
            int s2_dep = 0;

            for(auto &it2 : v) {
                if(it2.first->getNum() == it.first->getNum()) {
                    s2_dep = it2.second;
                    break;
                }
            }
            
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

        std::make_heap(std::begin(v), std::end(v), compare_d);
    }

    return r;
}

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