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
Peak::Peak(int num):m_num{num}, m_mark(marking::unsee){}

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
 * @return const std::vector<std::pair<const Peak*, double>>std::vector<const Peak*>& a vector containing all the successors of the peak
 */
const std::vector<std::pair<const Peak*, double>>& Peak::getSuccessors()const {
    return m_successeurs;
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
 * @param d the distance to the successor
 */
void Peak::addSucc(const Peak*s, double d){
    m_successeurs.push_back({s, d});
}

/**
 * @brief Overloaded flux operator to print a peak
 * 
 * @param os a flux
 * @param x a peak
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Peak &x) {
    os << "     Peak " << x.m_num << " : ";
    for (auto s : x.m_successeurs) {
        os << s.first->getNum() << " ";
        os << ', distance : ' << s.second << ' ';
    }
    return os;
}