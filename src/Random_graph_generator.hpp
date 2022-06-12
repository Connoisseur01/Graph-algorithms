#pragma once
#include "List.hpp"
#include "Matrix.hpp"

class Random{

    public:
    static void generate_random_graphs(List& list, Matrix& matrix, int edges, int vertiecies);
};