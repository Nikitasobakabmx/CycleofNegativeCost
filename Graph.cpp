#include "Graph.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

Graph::Graph()
{
    
}

Graph::Graph(const edge &item)
{
    graph.push_back(item);
}

Graph::Graph(const std::string &name)
{   
    this->openDOT(name);
}

Graph::Graph(const Graph &graph)
{
    //this->graph = graph;
}

std::string Graph::setName(std::string name)
{
	nameGraph = name;	 
}

bool Graph::saveToDOT(const std::string &name)
{	
	if(graph.empty())
		return false;
	std::ostream ost(name.c_str());
	ost << "digraph " << name << " {\n";
	for(auto i = graph.begin(); i != graph.end(), ++i)
	{
		ost << "\t" << i.a << "->" << i.b;
		ost << "[weight = " << i.const <<", label = " << i.cost << "];\n";
	}
	ost << "}";
	return true;
}

bool Graph::openTXT(const std::string &name)
{
	std::ifstream file;
	file.open(name);
	if(!file.is_open())
		return false;
	if(pFile.peek() == std::ifstream::traits_type::eof())
		return false;
	file.ignore(6);
	file >> nodes;
	file.ignore(6);
	file >> edges;
	file.ignore(10);
	while(file.eof())
	{
		edge *tmp;
		file >> tmp->a;
		file.ignore(2);
		file >> tmp->b;
		file.ignore(8);
		file >> tmp->cost;
		graph.push_back(tmp);
	}
	return true;
}

bool Graph::openDOT(const std::string &name)
{
	std::ifstream file;
	file.open(name);
	std::string tmp, rubish;
	file >> rubish >> tmp >> rubish;
	while(file.eof())
	{
		edge etmp;
		file >> etmp.a >> rubish >> etmp.b >> rubish >> rubish >> rubish >> etmp.weight >>
			 rubish >> rubish >> rubish >> rubish;
	}

}

bool Graph::saveToDOT()
{

}

bool Graph::openDOT()
{

}

bool Graph::serchNegativeCycle()
{
	if(graph.size() == 0)
		return false;
    std::vector<int> d (nodes, 0);
	std::vector<int> p (nodes, -1);
	int x;
	for (int i=0; i<nodes; ++i) 
	{
		x = -1;
		for (int j=0; j<edges; ++j)
			if (d[graph[j].b] > d[graph[j].a] + graph[j].cost) 
			{
				d[graph[j].b] = std::max (-INF, d[graph[j].a] + graph[j].cost);
				p[graph[j].b] = graph[j].a;
				x = graph[j].b;
			}
	}
 	if (x == -1)
		return false;
	else 
	{
		int y = x;
		for (int i=0; i<nodes; ++i)
			y = p[y];
 		if(path.size() != 0)
			path.clear();
		for (int cur=y; ; cur=p[cur]) {
			path.push_back(cur);
			if (cur == y && path.size() > 1)  break;
		}
		std::reverse (path.begin(), path.end());
	}
	return true;
		// for (int i=0; i<path.size(); ++i)
		// 	cout << path[i] << ' ';
}

void Graph::showNegativeCycle()
{
	if(path.size() != 0)
		return;
	for (int i=0; i<path.size(); ++i)
		std::cout << path[i] << ' ';
}

Graph::~Graph()
{
    this->saveToDOT();
}