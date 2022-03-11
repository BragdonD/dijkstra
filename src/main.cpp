#include <iostream>
#include "graph.hpp"

int main(int argc, char const *argv[])
{
    Graph g("graph.txt");

    std::cout << g;
    
    return 0;
}
