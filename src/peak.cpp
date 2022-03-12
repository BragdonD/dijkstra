/**
 * @file peak.cpp
 * @author DUCLOS Thomas - KEBE Ibrahim
 * @brief peak class's source file
 * @version 0.2
 * @date 2022-03-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "peak.hpp"

/**
 * @brief Construct a new Peak:: Peak object
 * 
 * @param num Value contain inside the peak
 */
Peak::Peak(int num):m_num{num}, m_predecessor(NULL), m_mark(marking::unsee){}

/**
 * @brief Destroy the Peak:: Peak object
 */
Peak::~Peak(){}

/**
 * @brief Getter for peak's value
 * 
 * @return int 
 */
int Peak::getNum()const{
    return m_num;
}

/**
 * @brief Getter for Successors reference
 * 
 * @return const std::vector<std::pair<const Peak*, double>>& a vector containing all the peak's successors and their distance to the peak
 */
const std::vector<std::pair<const Peak*, double>>& Peak::getSuccessors() const {
    return m_successors;
}

/**
 * @brief Getter for the peak's marking state
 * 
 * @return const marking (unsee, treatment, visited)
 */
const marking Peak::getMarking()const {
    return m_mark;
}

/**
 * @brief Setter for peak's marking state
 * 
 * @param mark 
 */
void Peak::setMarking(marking mark) {
    m_mark = mark;
}

/**
 * @brief Add a successor to the successors vector
 * 
 * @param s the peak to add
 * @param d the arc's weight between the peak and the successor
 */
void Peak::addSucc(const Peak*s, double d){
    m_successors.push_back({s, d});
}

/**
 * @brief Overloaded flux operator to print a peak
 * 
 * @param os a flux
 * @param x a peak
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Peak &x) {
    os << "     Peak " << x.m_num << " : " << std::endl;
    for (auto s : x.m_successors) {
        os << '\t' << s.first->getNum() << " ";
        os << "- distance : " << s.second << ";" << std::endl;
    }
    return os;
}

/**
 * @brief getter of the peak's predecessor
 * 
 * @return const Peak* the predecessor's peak
 */
const Peak* Peak::getPredecessor() const {
    return m_predecessor;
}

/**
 * @brief setter of the peak's predecessor
 * 
 * @param p the predecessor's peak
 */
void Peak::setPredecessor(Peak* p) {
    m_predecessor = p;
}