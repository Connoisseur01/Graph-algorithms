#include "Benchmark.hpp"
#include "Counter.hpp"
#include "List.hpp"
#include "Matrix.hpp"
#include <fstream>
#include <iostream>
#include "Random_graph_generator.hpp"
#include "Kruskal.hpp"
#include "Prim.hpp"
#include "ShortestPath.hpp"
#include "Heap.hpp"
#define REPETITIONS 20

Result Benchmark::test_kruskal(int verticies, int density, int repetitions){

    Matrix matrix;
    List list;
    Random random;
    Heap heap;

    int listTime = 0, matrixTime = 0;


    int edges = (int)(((density/100.0f)*(float)(verticies)*(float)(verticies - 1)) / 2.0f);

    for(int i = 0; i < repetitions; i++){

        Kruskal kruskal(verticies);
        Counter counter;
        random.generate_random_graphs(list, matrix, edges, verticies);

        counter.startCounter();
        std::vector<Edge> list_edges = list.get_edges();
        heap.heap_sort_edges(list_edges);
        kruskal.list_MST(list_edges);
        counter.stopCounter();

        listTime += counter.getCounter();

        counter.startCounter();
        std::vector<Edge> matrix_edges = matrix.get_edges();
        heap.heap_sort_edges(matrix_edges);
        kruskal.matrix_MST(matrix_edges);
        counter.stopCounter();

        matrixTime += counter.getCounter();
    }

    matrixTime = matrixTime/repetitions;
    listTime = listTime/repetitions;
    
    return {listTime, matrixTime};
}

Result Benchmark::test_prim(int verticies, int density, int repetitions){
    Matrix matrix;
    List list;
    Random random;

    int listTime = 0, matrixTime = 0;


    int edges = (int)(((density/100.0f)*(float)(verticies)*(float)(verticies - 1)) / 2.0f);

    for(int i = 0; i < repetitions; i++){

        Prim prim(verticies);
        Counter counter;
        random.generate_random_graphs(list, matrix, edges, verticies);

        counter.startCounter();
        prim.list_MST(list.get_non_directed_adjecency_list());
        counter.stopCounter();

        listTime += counter.getCounter();

        counter.startCounter();
        prim.matrix_MST(matrix.get_non_directed_edges());
        counter.stopCounter();

        matrixTime += counter.getCounter();
    }

    matrixTime = matrixTime/repetitions;
    listTime = listTime/repetitions;
    
    return {listTime, matrixTime};
}

Result Benchmark::test_bellmanFord(int verticies, int density, int repetitions){

    Matrix matrix;
    List list;
    Random random;

    int listTime = 0, matrixTime = 0;


    int edges = (int)(((density/100.0f)*(float)(verticies)*(float)(verticies - 1)) / 2.0f);

    for(int i = 0; i < repetitions; i++){

        ShortestPath sp(verticies);
        Counter counter;
        random.generate_random_graphs(list, matrix, edges, verticies);

        counter.startCounter();
        sp.bellman_ford(list.get_edges(), 0);
        counter.stopCounter();

        listTime += counter.getCounter();

        counter.startCounter();
        sp.bellman_ford(matrix.get_edges(), 0);
        counter.stopCounter();

        matrixTime += counter.getCounter();
    }

    matrixTime = matrixTime/repetitions;
    listTime = listTime/repetitions;
    
    return {listTime, matrixTime};
}

Result Benchmark::test_dijkstra(int verticies, int density, int repetitions){

    Matrix matrix;
    List list;
    Random random;

    int listTime = 0, matrixTime = 0;


    int edges = (int)(((density/100.0f)*(float)(verticies)*(float)(verticies - 1)) / 2.0f);

    for(int i = 0; i < repetitions; i++){

        ShortestPath sp(verticies);
        int start = 0;
        Counter counter;
        random.generate_random_graphs(list, matrix, edges, verticies);

        counter.startCounter();
        sp.dijkstra(list.get_edges(), start);
        counter.stopCounter();

        listTime += counter.getCounter();

        counter.startCounter();
        sp.dijkstra(matrix.get_edges(), start);
        counter.stopCounter();

        matrixTime += counter.getCounter();
    }

    matrixTime = matrixTime/repetitions;
    listTime = listTime/repetitions;
    
    return {listTime, matrixTime};    
}

void Benchmark::full_test_kruskal(){
    std::ofstream file("kruskal.csv");
    if(!file.is_open()){
        std::cout<<"kruskal.csv file did not open";
        return;
    }

    Result time;
    int v, density;
    v = 20;
    density = 25;

    file << "vertices, density, matrix_time, list_time\n\n";

    for(int i = 0; i < 5; i++){
        
        for(int k = 0; k < 4; k++){
            if(density == 100) density -= 1;
            time = test_kruskal(v, density, REPETITIONS);
            file << v << ", " << density << ", " << time.matrix_time << ", " << time.list_time <<'\n';
            density += 25;
        }
        density = 25;
        v += 40;
    }
}

void Benchmark::full_test_prim(){
    std::ofstream file("prim.csv");
    if(!file.is_open()){
        std::cout<<"prim.csv file did not open";
        return;
    }

    Result time;
    int v, density;
    v = 20;
    density = 25;

    file << "vertices, density, matrix_time, list_time\n\n";

    for(int i = 0; i < 5; i++){
        
        for(int k = 0; k < 4; k++){
            if(density == 100) density -= 1;
            time = test_prim(v, density, REPETITIONS);
            file << v << ", " << density << ", " << time.matrix_time << ", " << time.list_time <<'\n';
            density += 25;
        }
        density = 25;
        v += 40;
    }
}

void Benchmark::full_test_bellmanFord(){
    std::ofstream file("bellmanFord.csv");
    if(!file.is_open()){
        std::cout<<"bellmanFord.csv file did not open";
        return;
    }

    Result time;
    int v, density;
    v = 20;
    density = 25;

    file << "vertices, density, matrix_time, list_time\n\n";

    for(int i = 0; i < 5; i++){
        
        for(int k = 0; k < 4; k++){
            if(density == 100) density -= 1;
            time = test_bellmanFord(v, density, REPETITIONS);
            file << v << ", " << density << ", " << time.matrix_time << ", " << time.list_time <<'\n';
            density += 25;
        }
        density = 25;
        v += 40;
    }
}

void Benchmark::full_test_dijkstra(){
    std::ofstream file("dijkstra.csv");
    if(!file.is_open()){
        std::cout<<"dijkstra.csv file did not open";
        return;
    }

    Result time;
    int v, density;
    v = 20;
    density = 25;

    file << "vertices, density, matrix_time, list_time\n\n";

    for(int i = 0; i < 5; i++){
        
        for(int k = 0; k < 4; k++){
            if(density == 100) density -= 1;
            time = test_dijkstra(v, density, REPETITIONS);
            file << v << ", " << density << ", " << time.matrix_time << ", " << time.list_time <<'\n';
            density += 25;
        }
        density = 25;
        v += 40;
    }
}