/**
 * @file graph.cpp
 * @author DUCLOS Thomas - KEBE Ibrahim
 * @brief graph class's source file
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <queue>
#include <algorithm>
#include <exception>
#include "graph.hpp"

/**
 * @brief Construct a new Graph:: Graph object
 * 
 * @param nomFichier name of the file with the graph configuration
 */
Graph::Graph(std::string nomFichier) {
    std::ifstream ifs{nomFichier};
    if (!ifs) {
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    }

    ifs >> m_orientation;
    if ( ifs.fail() ) {
        throw std::runtime_error("Probleme lecture orientation du Graph");
    }

    int ordre;
    ifs >> ordre;
    if ( ifs.fail() ) {
        throw std::runtime_error("Probleme lecture ordre du Graph");
    }
        
    int taille;
    ifs >> taille;
    if ( ifs.fail() ) {
        throw std::runtime_error("Probleme lecture taille du Graph");
    }
        
    for (int i=0; i<ordre; ++i) {
        m_Peaks.push_back( new Peak{i} );
    }
        
    int peak, succ, arc;

    for (int i=0;i<taille;++i){
        ifs >> peak >> succ >> arc;
        if ( ifs.fail() ) {
            throw std::runtime_error("Probleme lecture arc");
        }
        m_Peaks[peak]->addSucc(m_Peaks[succ], (double)arc);

        ///si le Graph n'est pas orienté
        ///si num2 est successeur de num1, num1 est successeur de num2
        if(m_orientation == 0) {
            m_Peaks[succ]->addSucc(m_Peaks[peak], arc);
        }
    }
}

/**
 * @brief Getter for a particular peak
 * 
 * @param nb the peak's id
 * @return Peak* the found peak else NULL
 */
Peak* Graph::getPeak(int nb) const { 
    for(const auto it : m_Peaks) {
        if(it->getNum() == nb) {
            return it;
        }
    }
    return NULL;
}

/**
 * @brief getter of every peaks in the graph
 * 
 * @return std::vector<Peak*> containing all the peaks
 */
std::vector<Peak*> Graph::getPeaks() const {
    return m_Peaks;
}

/**
 * @brief Destroy the Graph:: Graph object
 * 
 */
Graph::~Graph() {
    for (auto s : m_Peaks)
        delete s;
}

/**
 * @brief Overloaded flux operator to print a graph and its peaks
 * 
 * @param os a flux
 * @param x a graph
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Graph &x) {
    os << std::endl << "Graph ";
    if(x.m_orientation) {
        os << "oriente" << std::endl << "  ";
    }
    else {
        os << "non oriente" << std::endl << "  ";
    }
    os << "ordre = " << x.m_Peaks.size() << std::endl << "  ";
    os << "listes d'adjacence :" << std::endl;
    for (auto s : x.m_Peaks){
        os << *s;
        os << std::endl;
    }
    return os;
}

/**
 * @brief Reset every Predecessor
 * 
 */
void Graph::resetPeaks() {
    for(auto &it : m_Peaks) {
        it->setPredecessor(NULL);
    }
}