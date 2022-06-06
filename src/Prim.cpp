#include "Prim.hpp"
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <queue>


bool operator < (const Vertex& a, const Vertex& b){
    return a.key > b.key;
}


void Prim::MST(std::vector<std::vector<Edge>> adj, int start){
    
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

    std::cout<<'\n';
    for(int i = 1; i < verticies; i++){
        std::cout<<i<<" -- "<<parent[i]<<" w = " <<key[i]<<'\n';
    }
}