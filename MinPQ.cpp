//
// Created by adries on 2021-04-07.
//

#include "MinPQ.h"
#include "Vertex.h"

#include <iostream>
#include <vector>

MinPQ::MinPQ(Vertex* vertexSet, const int numOfVerticies) {
    max_size = numOfVerticies;
    // Allocated mem for both the heap and the array to track the positions of elements
    A = new Vertex[max_size];
    pos = new int[max_size];

    // Assign values to these arrays
    for (std::size_t i = 0; i < max_size; i++) {
        A[i] = vertexSet[i];
        pos[i] = i;
    }

    // Set the current size to the max size
    current_size = max_size;
}

bool MinPQ::isEmpty() const {
    return current_size == 0;
}


void MinPQ::swap(Vertex *m, Vertex *n) {
    Vertex temp = *m;
    *m = *n;
    *n = temp;
}

int MinPQ::parent(const int i) const {
    return (i-1) / 2;
}

int MinPQ::left(const int i) const {
    return ((2*i) + 1);
}

int MinPQ::right(const int i) const {
    return ((2*i) + 2);
}

void MinPQ::heapify(int i) {
    int min = i;
    int l = left(i);
    int r = right(i);

    if ((l < current_size) && (A[l].getKey() < A[min].getKey())) {
        min = l;
    }

    if ((r < current_size) && (A[r].getKey() < A[min].getKey())) {
        min = r;
    }

    if (min != i) {
        Vertex minVertex = A[min];
        Vertex iVertex = A[i];

        // Perform swap of positions and values if the parent is greater than
        // the left or right child

        pos[minVertex.getVertexNumber()] = i;
        pos[iVertex.getVertexNumber()] = min;

        swap(&A[min], &A[i]);

        // Call heapify recursively
        heapify(min);
    }

}

Vertex MinPQ::extractMin() {
    // Pop the first element of the heap
    Vertex min = A[0];
    int tmp = current_size - 1;

    Vertex last = A[tmp];

    // Set the first element to the last element
    A[0] = last;

    // Do the same in the position array
    pos[min.getVertexNumber()] = tmp;
    pos[last.getVertexNumber()] = 0;

    // Decrease size
    current_size--;

    // Rebuild heap from the root (which is now the largest element)
    heapify(0);

    // Return the smallest element
    return min;
}

void MinPQ::modifyKey(const int v, const double newKey) {
    int i = pos[v];

    // Set the key of the vertex to the new key
    A[i].setKey(newKey);

    // While the parent of the modified key is greater than
    // the newly modified key
    while ((i) && (A[i].getKey() < A[parent(i)].getKey())) {
        int tmp = parent(i);

        // Swap their positions

        pos[A[i].getVertexNumber()] = tmp;
        pos[A[tmp].getVertexNumber()] = i;

        swap(&A[i], &A[tmp]);

        i = tmp;
    }
}

bool MinPQ::isInPQ(const int v) {
    if (pos[v] < current_size) {
        return true;
    }
    else {
        return false;
    }
}

MinPQ::~MinPQ() {
    delete []A;

    delete []pos;
}