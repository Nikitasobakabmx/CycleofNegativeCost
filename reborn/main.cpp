#include <iostream>
#include "Graph.h"
#include "Edge.h"
#include "except.h"

int main(int argc, char *argv[])
{
    Graph firstGraph;
    std::string name;
    if(argc >=2)
        name = argv[1];
    else 
    {
        std::cout << "Insert file name : ";
        std::cin >> name;
    }
    try
    {
    firstGraph.openDot(name);
    }
    catch(except ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    std::cout << "Work start\nFile is open" << std::endl;
    try
    {
        if(firstGraph.findNegativeCost())
            firstGraph.saveToDot();
    }
    catch(except ex)
    {
        std::cout << ex.what() << std::endl;
    }
    std::cout << firstGraph;
    std::cout << "end" <<std::endl;
    return 0;
}
