#pragma once
#include "List.hpp"
#include "Matrix.hpp"



class Kruskal{

    public:

       Kruskal(int verticies);
       ~Kruskal(){delete[] parent; delete[] rank;};

       void print_edges(std::vector<Edge> edges);

       List list_MST(std::vector<Edge> sortedEdges);

       Matrix matrix_MST(std::vector<Edge> sortedEdges);


    private:

    int verticies = 0;

    int* parent;

    int* rank;

    void initialize_DSU();

    void make_set(int v);

    int find_set(int v);

    void unite_sets(int a, int b);
};