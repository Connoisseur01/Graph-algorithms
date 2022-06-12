#include <iostream>
#include "Matrix.hpp"
#include "List.hpp"
#include <time.h>
#include "Edge.hpp"
#include "Heap.hpp"
#include "Kruskal.hpp"
#include "Prim.hpp"
#include "ShortestPath.hpp"
#include "Random_graph_generator.hpp"
#include "Benchmark.hpp"

void menu(List List, Matrix matrix);
void benchmark();

int main(){

    srand(time(NULL));

    int option;
    std::cout<<"[1] menu\n";
    std::cout<<"[2] benchmark\n";
    std::cin>>option;
    switch(option){
        case 1:{
            List list;
            Matrix matrix;
            menu(list, matrix);
            break;
        }

        case 2:{
            benchmark();
            return 0;
        }

        default: return 0;
    }
}

void benchmark(){
    Benchmark benchmark;
    benchmark.full_test_kruskal();
    benchmark.full_test_prim();
    benchmark.full_test_bellmanFord();
    benchmark.full_test_dijkstra();
}

void menu(List list, Matrix matrix){
    int option = 0;
    while(option != 8){
        std::cout<<"\n---------------------------------\n";
        std::cout<<"[1] read from text file\n";
        std::cout<<"[2] generate random graph\n";
        std::cout<<"[3] print graphs\n";
        std::cout<<"[4] generate MST - Prim\n";
        std::cout<<"[5] generate MST - Kruskal\n";
        std::cout<<"[6] find shortest path - Djikstra\n";
        std::cout<<"[7] find shortest path - Bellman Ford\n";
        std::cout<<"[8] exit\n";
        std::cin>>option;

        switch (option)
        {
        case 1:{

            std::string filename;
            std::cout<<"\n filename: ";
            std::cin>>filename;

            list.read_txt(filename);
            matrix.read_txt(filename);

            break;
        }
            
        case 2:{

            int verticies;
            int edges;
            float density;

            std::cout<<"\nnumber of verticies: ";
            std::cin>>verticies;
            std::cout<<"density: ";
            std::cin>>density;

            edges = (int)(((density/100.0f)*(float)(verticies)*(float)(verticies - 1)) / 2.0f);
            
            Random random;
            random.generate_random_graphs(list, matrix, edges, verticies);
            
            break;
        }

        case 3:{

            std::cout<<'\n'<<"matrix:\n\n";
            matrix.print();

            std::cout<<"\n\n"<<"list:\n";
            list.print();

            break;
        }

        case 4:{

            if(matrix.is_empty() || list.is_empty()){
                std::cout<<"\nno graph\n";
                break;
            }

            matrix.print_non_directed();
            std::cout<<'\n';
            list.print_non_directed();

            Prim prim(list.get_verticies());

            std::vector<std::vector<Edge>> list_adj = list.get_non_directed_adjecency_list();
            
            std::cout<<"\nlist: \n\n";
            List list_MST = prim.list_MST(list_adj);
            list_MST.print_non_directed();
            
            
            std::cout<<"\nmatrix:\n\n";
            Matrix matrix_MST = prim.matrix_MST(matrix.get_non_directed_edges());
            matrix_MST.print_non_directed();

            std::cout<<"\nedges:\n";
            prim.print_edges(list_MST.get_edges());

            break;
        }

        case 5:{

            if(matrix.is_empty() || list.is_empty()){
                std::cout<<"\nno graph\n";
                break;
            }

            matrix.print_non_directed();
            std::cout<<'\n';
            list.print_non_directed();

            Kruskal kruskal(list.get_verticies());
            Heap heap;

            std::vector<Edge> list_edges = list.get_edges();
            heap.heap_sort_edges(list_edges);
            std::cout<<"\nlist: \n\n";
            List list_MST = kruskal.list_MST(list_edges);
            list_MST.print_non_directed();
            
            std::vector<Edge> matrix_edges = matrix.get_edges();
            heap.heap_sort_edges(matrix_edges);
            std::cout<<"\nmatrix:\n\n";
            Matrix matrix_MST = kruskal.matrix_MST(matrix_edges);
            matrix_MST.print_non_directed();

            std::cout<<"\nedges:\n";
            kruskal.print_edges(list_MST.get_edges());


            break;
        }
        
        case 6:{

            if(matrix.is_empty() || list.is_empty()){
                std::cout<<"\nno graph\n";
                break;
            }

            ShortestPath sp(list.get_verticies());
            int start = -1, end = -1;

            
            std::cout<<"\nstart vertex: ";
            std::cin>>start;
            std::cout<<"end vertex: ";
            std::cin>>end;
            if(start > list.get_verticies()-1 || end > list.get_verticies()-1 || start < 0 || end < 0){
                std::cout<<'\n'<<"no such vertex!";
                break;
            }
            Path list_path = sp.dijkstra(list.get_edges(), start);

            std::cout<<"\nfor list: \n\n";
            sp.print_shortest_path(list_path, end);

            Path matrix_path = sp.dijkstra(matrix.get_edges(), start);

            std::cout<<"\n\nfor matrix: \n\n";
            sp.print_shortest_path(matrix_path, end);

            break;
        }

        case 7:{

            if(matrix.is_empty() || list.is_empty()){
                std::cout<<"\nno graph\n";
                break;
            }

            ShortestPath sp(list.get_verticies());
            int start = -1, end = -1;

            
            std::cout<<"\nstart vertex: ";
            std::cin>>start;
            std::cout<<"end vertex: ";
            std::cin>>end;
            if(start > list.get_verticies()-1 || end > list.get_verticies()-1 || start < 0 || end < 0){
                std::cout<<'\n'<<"no such vertex!";
                break;
            }
            Path list_path = sp.bellman_ford(list.get_edges(), start);

            std::cout<<"\nfor list: \n\n";
            sp.print_shortest_path(list_path, end);

            Path matrix_path = sp.bellman_ford(matrix.get_edges(), start);

            std::cout<<"\n\nfor matrix: \n\n";
            sp.print_shortest_path(matrix_path, end);

            break;
        }

        case 8:{
            return;
        }

        default:
            std::cout<<"\nwrong input!\n";
            break;
        }
    }  
}

