#pragma once
#include <iostream>
#include "Edge.hpp"
#include <vector>


class List{
    public:

       // List();
       // ~List();

        void read_txt(std::string filepath);

        void print();

        std::vector<Edge> get_edges();

        void generate_random(int vertex_number, int density);

        int get_verticies(){return verticies;}; 

    private:

    int edges, verticies;

    std::vector<std::vector<Edge>> list;


};