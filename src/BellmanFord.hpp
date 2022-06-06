#pragma once
#include "Edge.hpp"
#include <vector>

class BellmanFord{

    public:

        BellmanFord(int verticies){this->verticies = verticies;};

        void shortest_path(std::vector<Edge> edges, int start);

    private:

    int verticies;
};