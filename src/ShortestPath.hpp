#pragma once
#include "Edge.hpp"
#include <vector>

struct Path{
    std::vector<int> parents;
    std::vector<int> distances;
};

struct Distance{
    int vertex;
    int distance;
};

class ShortestPath{

    public:

        ShortestPath(int verticies){this->verticies = verticies;};

        Path bellman_ford(std::vector<Edge> edges, int start);

        Path dijkstra(std::vector<Edge> edges, int start);

        void print_shortest_path(Path path, int end);


    private:

    std::vector<Edge> get_vertex_edges(int vertex, std::vector<Edge> edges);

    int verticies;
};