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

        void print_edges(std::vector<Edge> edges);

        List list_MST(std::vector<std::vector<Edge>> adj, int start = 0);

        Matrix matrix_MST(std::vector<Edge> edges, int start = 0);

    private:

        std::vector<Edge> get_vertex_edges(int vertex, std::vector<Edge> edgeList);

        int verticies = 0;

};