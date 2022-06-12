#include "Kruskal.hpp"
#include "List.hpp"
#include <iostream>

Kruskal::Kruskal(int verticies){
    this->verticies = verticies;
    parent = new int[verticies];
    rank = new int[verticies];
}

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

void Kruskal::print_edges(std::vector<Edge> edges){
    int sumOfweights = 0;

    std::cout<<'\n';
    for(int i=0; i < edges.size(); i++){
        sumOfweights += edges[i].weight;
        std::cout<< edges[i].x << " -- " << edges[i].y << " weight = " << edges[i].weight<<'\n';
    }

    std::cout<<"\ntotal weight: "<<sumOfweights;
}


List Kruskal::list_MST(std::vector<Edge> sortedEdges){

    List result(verticies);

    for(int i = 0; i < verticies; i++){
        make_set(i);
    }


    for(int i = 0; i < sortedEdges.size(); i++){

        if (find_set(sortedEdges[i].x) != find_set(sortedEdges[i].y)) {
                unite_sets(sortedEdges[i].x, sortedEdges[i].y);
                
                result.add_edge(sortedEdges[i].x, sortedEdges[i].y, sortedEdges[i].weight);
        }
    }
    return result;
}

Matrix Kruskal::matrix_MST(std::vector<Edge> sortedEdges){
    Matrix result(verticies, verticies-1);

    for(int i = 0; i < verticies; i++){
        make_set(i);
    }


    for(int i = 0; i < sortedEdges.size(); i++){

        if (find_set(sortedEdges[i].x) != find_set(sortedEdges[i].y)) {
                unite_sets(sortedEdges[i].x, sortedEdges[i].y);
                
                result.add_edge(sortedEdges[i].x, sortedEdges[i].y, sortedEdges[i].weight);
        }
    }
    return result;
}
