#include <list>
#include <string>
#include <vector>

struct edge{
    int a, b;
    int cost;
};

class Graph
{
private:
    int nodes, edges;
    std::string nameGraph;
    std::vector<edge> graph;
    std::vector<int> path;
    const int INF = 1000000000;
public:
    Graph();
    Graph(const edge &item);
    Graph(const std::string &name);
    Graph(const Graph &graph);
    std::string setName(std::string name);
    bool openTXT(const std::string &name);
    bool saveToDOT(const std::string &name);
    bool openDOT(const std::string &name);
    bool saveToDOT();
    bool openDOT();
    bool serchNegativeCycle();
    void showNegativeCycle();
    ~Graph();
};