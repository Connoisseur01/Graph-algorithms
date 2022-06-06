#include "BellmanFord.hpp"
#include <limits.h>
#include <iostream>

void BellmanFord::shortest_path(std::vector<Edge> edges, int start){

    std::vector<int> distance(verticies, INT_MAX);
    std::vector<int> parent(verticies, -1);

    distance[start] = 0;

    for(int i = 1; i < verticies; i++){

        for(int k = 0; k < edges.size(); k++){
            
            int u = edges[k].x;
            int v = edges[k].y;

            if(distance[u] != INT_MAX && distance[u] + edges[k].weight < distance[v]){
                distance[v] = distance[u] + edges[k].weight;
                parent[v] = u;
            }
        }
    }

    std::cout<<'\n'<<start<<" -> 4 : ";
    int i = 2;

    while(parent[i] != -1){
        std::cout<<parent[i]<<" ";
        i = parent[i];
    }
    std::cout<<"distance="<<distance[2]<<'\n';
}