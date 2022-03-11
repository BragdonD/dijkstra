/**
 * @file peak.h
 * @author DUCLOS Thomas - KEBE Ibrahim
 * @brief peak class's header file
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#if !defined(PEAK_HPP)
#define PEAK_HPP

#include <iostream>
#include <vector>

/**
 * @brief Pseudo class to mark peak
 * 
 */
enum class marking {
    unsee = 0,
    visited = 2
};

class Peak{
    private :
        int m_num;
        std::vector<std::pair<const Peak*, double>> m_successeurs;
        marking m_mark;

    public :
        Peak(int num);
        ~Peak();
        int getNum() const;
        const std::vector<std::pair<const Peak*, double>>& getSuccessors() const;
        const marking getMarking() const;
        void setMarking(marking mark);
        void addSucc(const Peak*s, double d);
        friend std::ostream& operator<<(std::ostream& os, const Peak &x);

};

#endif // PEAK_HPP
