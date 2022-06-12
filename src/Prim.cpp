#include "Prim.hpp"
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <queue>


bool operator < (const Vertex& a, const Vertex& b){
    return a.key > b.key;
}

void Prim::print_edges(std::vector<Edge> edges){
    int sumOfweights = 0;

    std::cout<<'\n';
    for(int i=0; i < edges.size(); i++){
        sumOfweights += edges[i].weight;
        std::cout<< edges[i].x << " -- " << edges[i].y << " weight = " << edges[i].weight<<'\n';
    }

    std::cout<<"\ntotal weight: "<<sumOfweights;
}

std::vector<Edge> Prim::get_vertex_edges(int vertex, std::vector<Edge> edgeList){

    std::vector<Edge> result;

    for(int i = 0; i < edgeList.size(); i++){
        if(edgeList[i].x == vertex){
            result.push_back(edgeList[i]);
        }
    }    

    return result;
}

List Prim::list_MST(std::vector<std::vector<Edge>> adj, int start){
    
    List result(verticies);
    std::priority_queue<Vertex> Q;

    std::vector<int> key(verticies, INT_MAX);
    std::vector<int> parent(verticies, -1);
    std::vector<bool> inMST(verticies, false);

    Q.push({0, start});
    key[start] = 0;

    while(!Q.empty()){

        int u = Q.top().v;
        Q.pop();

        if(inMST[u] == true){
            continue;
        }

        inMST[u] = true;

        for(int i = 0; i < adj[u].size(); i++){

            int v = adj[u][i].y;
            int weight = adj[u][i].weight;

            if (inMST[v] == false && key[v] > weight)
            {
                
                key[v] = weight;
                Q.push({key[v], v});
                parent[v] = u;
            }
        }

    }

    for(int i = 1; i < verticies; i++){
        result.add_edge(i, parent[i], key[i]);
    }

    return result;
}

Matrix Prim::matrix_MST(std::vector<Edge> edges, int start){
    
    Matrix result(verticies, verticies-1);
    std::priority_queue<Vertex> Q;

    std::vector<int> key(verticies, INT_MAX);
    std::vector<int> parent(verticies, -1);
    std::vector<bool> inMST(verticies, false);

    Q.push({0, start});
    key[start] = 0;

    while(!Q.empty()){

        int u = Q.top().v;
        Q.pop();

        if(inMST[u] == true){
            continue;
        }

        inMST[u] = true;
        std::vector<Edge> u_edges = get_vertex_edges(u, edges);
        for(int i = 0; i < u_edges.size(); i++){

            int v = u_edges[i].y;
            int weight = u_edges[i].weight;

            if (inMST[v] == false && key[v] > weight)
            {
                
                key[v] = weight;
                Q.push({key[v], v});
                parent[v] = u;
            }
        }

    }

    for(int i = 1; i < verticies; i++){
        result.add_edge(i, parent[i], key[i]);
    }

    return result;
}