#include <iostream>
#include "List.hpp"
#include <fstream>
#include <time.h>

List::List(int verticies){
    this->verticies = verticies;
    for(int i = 0; i < verticies; i++){
        std::vector<Edge> vertex;
        list.push_back(vertex);
    }
    }

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

void List::add_edge(int vertex, int dest, int weight){
    list[vertex].push_back({vertex, dest, weight});
}

void List::print(){
    

    for(int i = 0; i < verticies; i++){
        std::cout<< i <<" = [";
        for(int k = 0; k < list[i].size(); k++){
            std::cout<<"("<<list[i][k].y<<", "<<list[i][k].weight<<") ";
        }
        std::cout<<"]\n";
    }
}

void List::print_non_directed(){

    std::vector<std::vector<Edge>> nd = get_non_directed_adjecency_list();

    for(int i = 0; i < verticies; i++){
        std::cout<< i <<" = [";
        for(int k = 0; k < nd[i].size(); k++){
            std::cout<<"("<<nd[i][k].y<<", "<<nd[i][k].weight<<") ";
        }
        std::cout<<"]\n";
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

void List::set_verticies(int verticies){
    this->verticies = verticies;

    for(int i = 0; i < verticies; i++){
        std::vector<Edge> vertex;
        list.push_back(vertex);
    }
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
