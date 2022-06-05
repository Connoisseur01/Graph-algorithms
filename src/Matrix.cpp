#include "Matrix.hpp"
#include <fstream>
#include <iostream>
#include <time.h>
#include "Edge.hpp"

void Matrix::read_txt(std::string filename){

    matrix.empty();

    std::ifstream input(filename);
    if(!input.is_open()){
        std::cout<<"file did not open";
        return;
    }

    
    input >> edges;
    input >> verticies;

    for(int i = 0; i < verticies; i++){
        std::vector<int> vertex;
        matrix.push_back(vertex);
    }

    for(int i = 0; i < edges; i++){
        int v1, v2, weight;
        input >> v1;
        input >> v2;
        input >> weight;
        add_edge(v1, v2, weight);
    }

    input.close();
}

void Matrix::add_edge(int v1, int v2, int weight){

    matrix[v1].push_back(weight);
    matrix[v2].push_back(-weight);

    for(int i = 0; i < verticies; i++){
        
        if(i == v1 || i == v2){
            continue;
        }
        else{
            matrix[i].push_back(0);
        }
    }
}

void Matrix::print(){

    for(int i = 0; i < verticies; i++){
        std::cout<<i<<" |";
        for(int k = 0; k < edges; k++){
            std::cout<<" "<<matrix[i][k]<<" ";
        }
        std::cout<<"|\n";
    }
}

void Matrix::generate_random(int edges, int density){

    this->edges = edges;

    matrix.empty();

    verticies = (edges*100)/density;

    for(int i = 0; i < verticies; i++){
        std::vector<int> vertex;
        matrix.push_back(vertex);
    }

    int v1 = 0, v2 = 0, weight;

    for(int i = 0; i < edges; i++){

        v1 = rand() % verticies;

        do{
            v2 = rand() % verticies;
        }while(v2 == v1);

        weight = rand() % 30;

        add_edge(v1, v2, weight);
    }
}

std::vector<Edge> Matrix::get_edges(){

    std::vector<Edge> edgeList;

    for(int i = 0; i < edges; i++){
        Edge edge;

        for(int k = 0; k < verticies; k++){

            if(matrix[k][i] != 0){
                if(matrix[k][i] > 0){
                    edge.weight = matrix[k][i];
                    edge.x = k;
                }else{
                    edge.y = k;
                }
            }
        }
        edgeList.push_back(edge);
    }

    return edgeList;
} 

