#include "Heap.hpp"


void Heap::heapify(std::vector<Edge>& tab,int size, int index){

   int largest = index;

   int left = 2 * index + 1;
   int right = 2 * index + 2;

   if (left < size && tab[left].weight > tab[largest].weight)
        largest = left;

    if (right < size && tab[right].weight > tab[largest].weight)
        largest = right;
    
    if (largest != index) {
        std::swap(tab[index], tab[largest]);
 
        heapify(tab, size, largest);
    }
}

void Heap::heap_sort_edges(std::vector<Edge>& tab){
    for (int i = tab.size() / 2 - 1; i >= 0; i--)
        heapify(tab, tab.size(), i);
    
    for (int i = tab.size() - 1; i > 0; i--) {

        std::swap(tab[0], tab[i]);

        heapify(tab, i, 0);
    }
}

