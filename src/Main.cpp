#include <iostream>
#include "Matrix.hpp"
#include "List.hpp"
#include <time.h>
#include "Edge.hpp"
#include "Heap.hpp"
#include "Kruskal.hpp"

int main(){

    srand(time(NULL));

    Heap heap;

    List list;
    list.read_txt("graph.txt");

    std::vector<Edge> listEdges = list.get_edges();
    heap.heap_sort_edges(listEdges);
    
    
    Kruskal listKruskal(list.get_verticies());
    listKruskal.MST(listEdges);
   

    Matrix matrix;
    matrix.read_txt("graph.txt");

    std::vector<Edge> matrixEdges = matrix.get_edges();
    heap.heap_sort_edges(matrixEdges);


    Kruskal matrixKruskal(matrix.get_verticies());
    matrixKruskal.MST(matrixEdges);
}