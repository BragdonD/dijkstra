/**
 * @file cli.h
 * @author DUCLOS Thomas - KEBE Ibrahim
 * @brief client interface's header file
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#if !defined(CLI_HPP)
#define CLI_HPP

#include <iostream>
#include <limits>

namespace cli {
    int getInteger();
    void menu();
}

#endif // CLI_HPP
