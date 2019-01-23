#include "except.h"
#include "Graph.h"
#include <fstream>
#include <iostream>
#include <map>
#include <algorithm>

Graph::Graph()
{

}
Graph::Graph(std::string name)
{
    this->openDot(name);
}
Graph::Graph(Graph& copy)
{
    this->name = copy.name;
    this->edges = copy.edges;
    this->nodes = copy.nodes;
    if(copy.enteredGraph != NULL)
        this->enteredGraph = new std::list<Edge>(*(copy.enteredGraph));
    if(copy.negativeCostGraph != NULL)
        this->negativeCostGraph = new std::list<Edge>(*(copy.negativeCostGraph));
}

void Graph::show()
{
    std::cout<<(*this);
}



void Graph::openDot(std::string name)//ebat' kostil'
{
    std::ifstream fromFile(name);
    if(!fromFile.is_open())
        throw except((char*)"File isn\'t exist!");
    std::string tmp;
    fromFile >> tmp >> this->name >> tmp;
    if(enteredGraph != NULL)
    {
        enteredGraph->clear();
        enteredGraph = NULL;
    }
    enteredGraph = new std::list<Edge>;//conteiner of entered graph
    edges = 0;
    if(nodesName != NULL)//conteiner of names
        delete nodesName;
    nodesName = new std::list<std::string>;
    while(!fromFile.eof())
    {   
        Edge eTmp;
        fromFile >> eTmp;
        if(eTmp.a == "}")
            break;
        ++edges;
        bool chekA = true;
        bool chekB = true;
        bool chekE = true;
        for(auto it = enteredGraph->begin(); it != enteredGraph->end(); ++it)
        {
            if((eTmp.a == it->a) || (eTmp.a ==it->b))
                chekA = false;
            if((eTmp.b == it->a) || (eTmp.b ==it->b))
                chekB = false;
        }   
        if(eTmp.a == eTmp.b)
            chekE = false;
        if(chekA)
        {    
            nodesName->push_back(eTmp.a);
            nodes++;
        }
        if(chekB && chekE)
        {
            nodes++;
            nodesName->push_back(eTmp.b);
        }
        enteredGraph->push_back(eTmp);    
    }
    fromFile.close();
}

bool Graph::saveToDot()
{
    this->saveToDot("Test.dot", *this->negativeCostGraph);
}

bool Graph::saveToDot(std::string name)
{
    this->saveToDot(name, *this->negativeCostGraph);
}

bool Graph::saveToDot(std::list<Edge> Graph)
{
    this->saveToDot("Test.dot", Graph);
}

bool Graph::saveToDot(std::string name, std::list<Edge> Graph)
{
    std::ofstream toFile(name);
    if(Graph.empty())
        throw except((char*) "Graph is empty");
    if(this->name.empty())
        this->name = "graph";
    toFile << "digraph " << this->name << " {\n";
    for(std::list<Edge>::iterator it = Graph.begin(); it != Graph.end(); ++it)
        toFile << "\t" << *it << "\n";
    toFile << "}";
    toFile.close();
}
bool Graph::findNegativeCost()
{
    this->findNegativeCost(this->enteredGraph);
}
bool Graph::findNegativeCost(std::list<Edge> *Graph)
{
    for(auto it = nodesName->begin(); it != nodesName->end(); ++it)
    {
        if(enteredGraph == NULL)
            throw except((char*) "Graph is empty");
        if(nodesName == NULL)
            throw except((char*) "Enyone Erorr\nnodesName is empty");
	    std::map<std::string, int> *d = new std::map<std::string, int>;
	    std::map<std::string, std::string> *p = new std::map<std::string, std::string>;
        for(auto itN = nodesName->begin(); itN != nodesName->end(); ++itN)
        {
            d->insert(std::pair<std::string, int>(*itN, 0));
            p->insert(std::pair<std::string, std::string>(*itN, "-1"));
        }
        (*d)[*it] = 0;
        std::string x;
	    for (int i=0; i<nodes; ++i)
        {
	    	x = "-1";
	    	for (auto itG = enteredGraph->begin(); itG != enteredGraph->end(); ++itG){
	     		if ((*d)[(*itG).b] > (*d)[(*itG).a] + (*itG).cost) 
                {
	     		    (*d)[(*itG).b] = std::max ((int)(-INFINITY), (int)((*d)[(*itG).a] + (*itG).cost));
	     			(*p)[(*itG).b] = (*itG).a;
	     			x = (*itG).b;
	     		}
                 
            }
	    }
    
	    if (x == "-1")
            continue;
	    else
        {
            
	    	std::string y = x;
	    	for (int i=0; i<nodes; ++i)
	     		y = (*p)[y];
    
	     	std::list<std::string> path;
	     	for (std::string cur=y; ; cur=(*p)[cur]) {
	     		path.push_back(cur);
	     		if (cur == y && path.size() > 1)  break;
	     	}
            negativeCostGraph = new std::list<Edge>;
	     	std::reverse (path.begin(), path.end());
            int count = 0;
         	for (auto itG = path.begin(); itG != --path.end(); ++itG)
            {
                Edge tmp;
                tmp = {(*itG), *(++itG), -1};
                --itG;
                negativeCostGraph->push_back(tmp);
            }
            return true;
        }
    }
    return false;
}
void Graph::operator +=(const Edge &edge)
{
    this->add(edge);
}
void Graph::add(const Edge &edge)
{
    if(this->enteredGraph == NULL)
    {
        this->enteredGraph = new std::list<Edge>;
        this->enteredGraph->push_back(edge);
        return;
    }
    this->enteredGraph->push_back(edge);    
}

std::ostream& operator<<(std::ostream &os, Graph &graph)
{
    if(graph.enteredGraph == NULL)
        throw except((char*)"Graph is empty");
    os << "\t!Entered Graph!\n";
    for(auto it : *graph.enteredGraph)
        os << it << "\n";
    if(graph.negativeCostGraph == NULL)
    {
        os << "Graph hasn\'t negative cycle!\n";
        return os;
    }
    os << "\t!Negative cycle!\n";
    for(auto it : *graph.negativeCostGraph)
        os << it << "\n";
    return os;
}

Graph::~Graph()
{
}