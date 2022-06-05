#pragma once
#include "List.hpp"



class Kruskal{

    public:

       Kruskal(int verticies){this->verticies = verticies;};
       ~Kruskal(){delete[] parent; delete[] rank;};

       void MST(std::vector<Edge> sortedEdges);


    private:

    int verticies = 0;

    int* parent = new int[verticies];

    int* rank = new int[verticies];

    void initialize_DSU();

    void make_set(int v);

    int find_set(int v);

    void unite_sets(int a, int b);
};