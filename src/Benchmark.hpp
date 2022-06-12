#pragma once

struct Result{
    int list_time;
    int matrix_time;
};

class Benchmark{

    public:

        Result test_kruskal(int verticies, int density, int repetitions);

        Result test_dijkstra(int verticies, int density, int repetitions);

        Result test_bellmanFord(int verticies, int density, int repetitions);

        Result test_prim(int verticies, int density, int repetitions);

        void full_test_kruskal();

        void full_test_prim();

        void full_test_dijkstra();

        void full_test_bellmanFord();

    private:

};