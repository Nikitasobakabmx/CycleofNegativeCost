#pragma once
#include <string>
#include <list>
#include <ostream>
#include "Edge.h"

class Graph
{
    private:
        std::string name;//имя графа
        const int INFINITY = 0xFFFF;//Бесконечное значение
        unsigned int edges = 0;//счетчик ребер
        unsigned int nodes = 0;//счетчик вершин
        std::list<Edge> *enteredGraph = NULL;//список вводимого графа
        std::list<Edge> *negativeCostGraph = NULL;//список найденого графа
        std::list<std::string> *nodesName = NULL;//список имен вершин
    public:
        Graph();
        Graph(std::string name);
        Graph(Graph& copy);
        void show();
        void openDot(std::string name);
        bool saveToDot();
        bool saveToDot(std::string name);
        bool saveToDot(std::list<Edge> Graph);
        bool saveToDot(std::string name, std::list<Edge> Graph);
        bool findNegativeCost();
        bool findNegativeCost(std::list<Edge> *Graph);
        void operator +=(const Edge &edge);
        void add(const Edge &edge);
        friend std::ostream& operator<<(std::ostream &os, Graph &graph);
        ~Graph();
};
