/**
 * @file graph.h
 * @author DUCLOS Thomas - KEBE Ibrahim
 * @brief graph's class header fike
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#if !defined(GRAPH_HPP)
#define GRAPH_HPP

#include <fstream>
#include <vector>
#include <exception>
#include <string>
#include <stack>
#include "peak.hpp"

class Graph{
    private :
        std::vector<Peak*> m_Peaks;
        int m_orientation;

    public :
        Graph(std::string nomFichier);
        ~Graph();
        Peak* getPeak(int nb) const;
        std::vector<Peak*> getPeaks() const;
        void resetPeaks();
        friend std::ostream& operator<<(std::ostream& os, const Graph &x);
};

#endif // GRAPH_HPP