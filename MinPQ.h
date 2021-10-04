//
// Created by adries on 2021-04-07.
//

#ifndef MST_MINPQ_H
#define MST_MINPQ_H

#include "Vertex.h"
#include <vector>

class MinPQ{
private:
    Vertex *A; // The array that makes up the PQ
    int *pos; // An array to map the positions of the elements in the PQ
    int max_size; // Max size of the PQ
    int current_size; // Current size of the PQ

public:
    MinPQ(Vertex* vertexSet, const int numOfVerticies);

    ~MinPQ();

    // Functions to access elements in the heap

    int parent(const int i) const;
    int left(const int i) const;
    int right(const int i) const;

    // Removes and returns the minimum value in the PQ
    Vertex extractMin();

    // Swaps two elements in the Heap
    void swap(Vertex *m, Vertex *n);

    // Rebuilds the heap from the node that was passed in
    void heapify(int i);

    // Checks to see if the PQ is empty
    bool isEmpty() const;

    // Rebuilds the heap when a key is changed
    void modifyKey(const int v, const double newKey);

    // Checks to see if an element is in the PQ
    bool isInPQ(const int v);

};

#endif //MST_MINPQ_H
