#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct edge{
    int a, b;
    int cost;
};

    int nodes, edges;
    std::string nameGraph;
    std::vector<edge> graph;
    std::vector<int> path;
    const int INF = 1000000000;

bool openTXT(const std::string name)
{
	std::ifstream file(name.c_str());
	if(!file.is_open())
		return false;
	if(file.peek() == std::ifstream::traits_type::eof())
		return false;
	file.ignore(7);
	file >> nodes;
	file.ignore(7);
	file >> edges;
	file.ignore(12);
	while(!file.eof())
	{
        file.ignore();
		edge *tmp;
		file >> tmp->a;
		file.ignore(4);
		file >> tmp->b;
        //std::cout << tmp->a << std::endl;
		file.ignore(10);
		file >> tmp->cost;
		graph.push_back(*tmp);
	}
    std::cout << "Tut normas\n";
	return true;
}


int main()
{
    std::cout << "Work start!\n";
    std::cout << openTXT("graph.txt") << std::endl;
    //std::cout << graph[0].a << std::endl;
    
}