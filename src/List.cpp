#include <iostream>
#include "List.hpp"
#include <fstream>
#include <time.h>

void List::read_txt(std::string filename){

    list.clear();

    std::ifstream input(filename);
    if(!input.is_open()){
        std::cout<<"file did not open";
        return;
    }

    

    input >> edges;
    input >> verticies;

    for(int i = 0; i < verticies; i++){
        std::vector<Edge> vertex;
        list.push_back(vertex);
    }

    int v1, v2, weight;

    for(int i = 0; i < edges; i++){
        
        input >> v1;
        input >> v2;
        input >> weight;
        Edge edge;
        edge.x = v1;
        edge.y = v2;
        edge.weight = weight;
        list[v1].push_back(edge);
    } 
    

    input.close();
}

void List::print(){
    
    std::cout<<"edge = (end_vertex, weight)\n\n";

    for(int i = 0; i < verticies; i++){
        std::cout<< i <<" = [";
        for(int k = 0; k < list[i].size(); k++){
            std::cout<<"("<<list[i][k].y<<", "<<list[i][k].weight<<") ";
        }
        std::cout<<"]\n";
    }
}

void List::generate_random(int edges, int density){

    list.clear();

    this->edges = edges;

    list.empty();

    verticies = (edges*100)/density;

    for(int i = 0; i < verticies; i++){
        std::vector<Edge> vertex;
        list.push_back(vertex);
    }

    int v1 = 0, v2 = 0, weight;

    for(int i = 0; i < edges; i++){
        
        v1 = rand() % verticies;
        
        do{
            v2 = rand() % verticies;
        }while(v1 == v2);

        weight = rand() % 30;
        Edge edge;
        edge.x = v1;
        edge.y = v2;
        edge.weight = weight;
        list[v1].push_back(edge);
    } 
}

std::vector<std::vector<Edge>> List::get_non_directed_adjecency_list(){

    std::vector<std::vector<Edge>> result = list;
    for(int i = 0; i < verticies; i++){
        for(int k = 0; k < list[i].size(); k++){
            Edge e = list[i][k];
            std::swap(e.x, e.y);
            result[e.x].push_back(e);
        }
    }
    return result;
}

std::vector<Edge> List::get_edges(){

    std::vector<Edge> edgeList;

    for(int i = 0; i < verticies; i++){
        for(int k = 0; k < list[i].size(); k++){
            Edge e = list[i][k];
            edgeList.push_back(e);
        }
    }

    return edgeList;
}
