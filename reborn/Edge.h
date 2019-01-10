#pragma once
#include <string>
#include <ostream>
#include <istream>
#include "except.h"

class Edge{
    public:
        std::string a;
        std::string b;
        int cost = 0;
        inline friend std::ostream& operator<< (std::ostream &os, const Edge& edge);
        inline friend std::istream& operator>> (std::istream &os, Edge& edge);
};

inline std::ostream& operator<< (std::ostream &os, const Edge& edge)
{
    if(edge.a.empty())
        throw except((char*)"Point A is empty");
    if(edge.b.empty())
        throw except((char*)"Point B is empty");
    os << edge.a << " -> " << edge.b <<" [cost = " << edge.cost << ", label = " << edge.cost << "]";
    return os;
}

inline std::istream& operator>> (std::istream &os, Edge& edge)
{
    std::string tmp;
    os >> edge.a >> tmp >> edge.b >> tmp >> tmp >> edge.cost;
    for (int i = 0; i < 4; i++)
        os >> tmp;
    return os;
}