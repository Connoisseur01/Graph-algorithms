#include "ShortestPath.hpp"
#include <limits.h>
#include <iostream>
#include <queue>

bool operator < (const Distance& a, const Distance& b) {
    return a.distance < b.distance;
}

Path ShortestPath::bellman_ford(std::vector<Edge> edges, int start){

    std::vector<int> distances(verticies, INT_MAX);
    std::vector<int> parents(verticies, -1);

    distances[start] = 0;

    for(int i = 1; i < verticies; i++){

        for(int k = 0; k < edges.size(); k++){
            
            int u = edges[k].x;
            int v = edges[k].y;

            if(distances[u] != INT_MAX && distances[u] + edges[k].weight < distances[v]){
                distances[v] = distances[u] + edges[k].weight;
                parents[v] = u;
            }
        }
    }

    Path path{parents, distances};
    return path;
}

Path ShortestPath::dijkstra(std::vector<Edge> edges, int start){

    std::vector<int> distances(verticies, INT_MAX);
    std::vector<int> parents(verticies, -1);
    std::priority_queue<Distance> Q;

    distances[start] = 0;

    Q.push({start, distances[start]});

    while(!Q.empty()){

        Distance u = Q.top();
        Q.pop();

        std::vector<Edge> adj = get_vertex_edges(u.vertex, edges);

        for(int i = 0; i < adj.size(); i++){
            if(distances[u.vertex] + adj[i].weight < distances[adj[i].y] && distances[u.vertex] != INT_MAX){
                distances[adj[i].y] = distances[u.vertex] + adj[i].weight;
                parents[adj[i].y] = u.vertex;
                Q.push({adj[i].y, distances[adj[i].y]});
            }
        }
    }

    Path path{parents, distances};
    return path;
}

std::vector<Edge> ShortestPath::get_vertex_edges(int vertex, std::vector<Edge> edges){

    std::vector<Edge> result;

    for(int i = 0; i < edges.size(); i++){
        if(edges[i].x == vertex){
            result.push_back(edges[i]);
        }
    }    

    return result;
}

void ShortestPath::print_shortest_path(Path path, int end){

    if(path.distances[end] == INT_MAX){
        std::cout<<"no path";
        return;
    }

    int i = end;
    std::cout<<end;
    while(path.parents[i] != -1){
       std::cout<<" <-- "<<path.parents[i];
        i = path.parents[i];
    }
    std::cout<<"\ndistance = "<<path.distances[end]<<'\n';
}