#include <iostream>
#include "Matrix.hpp"
#include "List.hpp"
#include <time.h>
#include "Edge.hpp"
#include "Heap.hpp"
#include "Kruskal.hpp"
#include "Prim.hpp"
#include "BellmanFord.hpp"

int main(){

    srand(time(NULL));

   

    Matrix matrix;
    matrix.read_txt("graph.txt");

    Prim prim(matrix.get_verticies());

    prim.MST(matrix.to_adj(), 0);

    //List list;
    //list.read_txt("graph.txt");

    //BellmanFord bf(list.get_verticies());
    //bf.shortest_path(list.get_edges(), 3);
}