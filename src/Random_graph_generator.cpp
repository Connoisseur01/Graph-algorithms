#include "Random_graph_generator.hpp"

void Random::generate_random_graphs(List& list, Matrix& matrix, int edges, int verticies){

    list.clear();
    matrix.clear();

    list.set_edges(edges);
    list.set_verticies(verticies);

    matrix.set_edges(edges);
    matrix.set_verticies(verticies);

    

    int number_of_edges_added = 0;
    std::vector<int> added;
    std::vector<int> notAdded;

    for(int i=0; i < verticies; i++){
        notAdded.push_back(i);
    }

    int x = notAdded.back();
    added.push_back(x);
    notAdded.pop_back();

    while(!notAdded.empty()){
        int i = rand() % notAdded.size();
        int v1 = notAdded[i];
        notAdded.erase(notAdded.begin() + i);

        i = rand() % added.size();
        int v2 = added[i];
        int weight = 1 + rand() % 30;
        matrix.add_edge(v1, v2, weight);
        list.add_edge(v1, v2, weight);
        number_of_edges_added++;

        added.push_back(v1);
    }

    while(edges != number_of_edges_added){
        int v1, v2, weight;

        v1 = rand() % verticies;
        do{
        v2 = rand() % verticies;
        }while(v1 == v2);
        weight = 1 + rand() % 30;

        matrix.add_edge(v1, v2, weight);
        list.add_edge(v1, v2, weight);
        number_of_edges_added++;
    }
}