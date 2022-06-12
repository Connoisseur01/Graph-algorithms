#include "Matrix.hpp"
#include <fstream>
#include <iostream>
#include <time.h>
#include <iomanip>
#include "Edge.hpp"

Matrix::Matrix(int verticies, int edges){
    this->verticies = verticies;
    this->edges = edges;

    for(int i = 0; i < verticies; i++){
        std::vector<int> vertex;
        matrix.push_back(vertex);
    }
}

void Matrix::read_txt(std::string filename){

    matrix.clear();

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
        std::cout<<i<<" |"<<std::setw(3);
        for(int k = 0; k < edges; k++){
            std::cout<<matrix[i][k]<<std::setw(4);
        }
        std::cout<<"|\n";
    }
}

void Matrix::print_non_directed(){
    for(int i = 0; i < verticies; i++){
        std::cout<<i<<" |"<<std::setw(2);
        for(int k = 0; k < edges; k++){
            std::cout<<abs(matrix[i][k])<<std::setw(4);
        }
        std::cout<<"|\n";
    }
}

void Matrix::set_verticies(int verticies){
    this->verticies = verticies;

    for(int i = 0; i < verticies; i++){
        std::vector<int> vertex;
        matrix.push_back(vertex);
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

std::vector<Edge> Matrix::get_non_directed_edges(){

    std::vector<Edge> result = get_edges();

    for(int i = 0; i < edges; i++){
        int v2 = result[i].x;
        int v1 = result[i].y;
        int weight = result[i].weight;

        result.push_back({v1, v2, weight});
    }    

    return result;
}

