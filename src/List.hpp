#pragma once
#include <iostream>
#include "Edge.hpp"
#include <vector>


class List{
    public:

       List(int verticies = 0);
       // ~List();

        void read_txt(std::string filepath); // read graph from text file

        void print(); // print list

        void print_non_directed(); // print list as non directed

        std::vector<Edge> get_edges(); //return list of edges

        int get_verticies(){return verticies;};

        void add_edge(int vertex, int dest, int weight); 

        std::vector<std::vector<Edge>> get_adjecency_list(){return list;}; //get adjency list
        std::vector<std::vector<Edge>> get_non_directed_adjecency_list(); // get adjency list converted to non directed
        
        void clear(){list.clear();}; //clear list graph

        void set_edges(int edges){this->edges = edges;}; //set edges number

        void set_verticies(int verticies); // set vertices number

        bool is_empty(){return list.empty();}; //return true if empty

    private:

    int edges, verticies;

    std::vector<std::vector<Edge>> list;


};