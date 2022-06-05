#pragma once
#include <vector>
#include "Edge.hpp"


class Heap{


    public:

    void heapify(std::vector<Edge>& tab, int size, int index);

    void heap_sort_edges(std::vector<Edge>& tab);



};