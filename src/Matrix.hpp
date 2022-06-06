#pragma once
#include <iostream>
#include "Edge.hpp"
#include <vector>

class Matrix{
    public:
        //Matrix();
       // ~Matrix();

        void add_edge(int v1, int v2, int weight);

        void read_txt(std::string filename);

        void generate_random(int edges, int density);

        std::vector<Edge> get_edges();

        std::vector<Edge> get_vertex_edges(int vertex);

        void print();

        int get_verticies(){return verticies;}; 

        std::vector<std::vector<Edge>> to_adj();


    private:

        int edges = 0, verticies = 0;
        std::vector<std::vector<int>> matrix;
};

