#include "Kruskal.hpp"
#include "List.hpp"
#include <iostream>

void Kruskal::make_set(int v){
    parent[v] = v;
    rank[v] = 0;
}

int Kruskal::find_set(int v){
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void Kruskal::unite_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            std::swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}


void Kruskal::MST(std::vector<Edge> sortedEdges){

    for(int i = 0; i < verticies; i++){
        make_set(i);
    }

    int sumOfweights = 0;

    std::cout<<'\n';
    for(int i = 0; i < sortedEdges.size(); i++){

        if (find_set(sortedEdges[i].x) != find_set(sortedEdges[i].y)) {
                unite_sets(sortedEdges[i].x, sortedEdges[i].y);
                sumOfweights += sortedEdges[i].weight;
                std::cout<< sortedEdges[i].x << " -- " << sortedEdges[i].y << " weight = " << sortedEdges[i].weight<<'\n';
        }
    }
    std::cout<<'\n'<<"total weight: "<<sumOfweights<<'\n';
}

