/**
 * @file cli.cpp
 * @author DUCLOS Thomas - KEBE Ibrahim
 * @brief client interface's source file
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "cli.hpp"

/**
 * @brief Function to write integer safely. If we had a wrong input, it is erase and re-ask.
 * 
 * @return int The written integer
 */
int cli::getInteger() {
    int integer;
    bool error(false);
    
    do{
        error = false;
        std::cout << "Write an integer : " << std::endl;
        std::cin >> integer;

        if(std::cin.fail()){
            error = true;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while(error);

    return integer;
}

void cli::menu() {
    std::cout << "MENU :" << std::endl;
    std::cout << "1. Print full Dijkstra results." << std::endl;
    std::cout << "2. Print result for an end peak" << std::endl;
    std::cout << "3. Print Graph." << std::endl;
    std::cout << "4. Exit." << std::endl;
}