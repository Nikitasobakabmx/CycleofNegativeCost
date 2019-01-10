#include <iostream>
#include "Graph.h"
#include "Edge.h"
#include "except.h"

int main(int argc, char *argv[])
{
    Graph firstGraph;
    firstGraph.openDot("example.dot");
    std::cout << "Work start\nFile is open" << std::endl;
    try{
    if(firstGraph.findNegativeCost())
        firstGraph.saveToDot();
    }catch(except ex)
    {
        std::cout << ex.what() << std::endl;
    }
    std::cout << firstGraph;
    std::cout << "end" <<std::endl;
    return 0;
}
