#pragma once
#include <iostream>
#include "Edge.hpp"
#include <vector>

class Matrix{
    public:
        Matrix(int verticies = 0, int edges = 0);

        void add_edge(int v1, int v2, int weight); //adds edge to matrix

        void read_txt(std::string filename); //reads matrix from txt file

        std::vector<Edge> get_edges(); //return list of edges

        void print(); // print graph

        void print_non_directed(); // print graph as non directed

        int get_verticies(){return verticies;};  //return vertices count

        std::vector<Edge> get_non_directed_edges(); //return list of non directed edges

        void clear(){matrix.clear();}; //clear matrix graph

        void set_edges(int edges){this->edges = edges;}; //set number of edges

        void set_verticies(int verticies); // set number of vertices

        bool is_empty(){return matrix.empty();}; // return 1 if empty

    private:

        int edges, verticies;
        std::vector<std::vector<int>> matrix;
};

