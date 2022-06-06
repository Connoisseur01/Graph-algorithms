#pragma once
#include "Edge.hpp"
#include "List.hpp"
#include "Matrix.hpp"
#include <queue>
#include <vector>

struct Vertex{
    int key;
    int v;
};

class Prim{
    public:

        Prim(int verticies){this->verticies = verticies;};

        void MST(std::vector<std::vector<Edge>> adj, int start);

    private:


        int verticies = 0;

};