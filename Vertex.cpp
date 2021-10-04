//
// Created by adries on 2021-04-07.
//

#include "Vertex.h"
#include <cmath>

//Default constructor
Vertex::Vertex() {
    vertexNumber = -1;
    key = INFINITY;
    parent = -1;
}

// Constructor with a vertex number passed in
Vertex::Vertex(const int vertNum) {
    vertexNumber = vertNum;
    key = INFINITY;
    parent = -1;
}

double Vertex::getKey() const {
    return key;
}

void Vertex::setKey(const double newKey) {
    key = newKey;
}

int Vertex::getVertexNumber() const {
    return vertexNumber;
}

void Vertex::setVertexNumber(const int newVertexNumber) {
    vertexNumber = newVertexNumber;
}

void Vertex::addAdjacent(const int v) {
    adjacents.push_back(Vertex(v));
}

// Find vertex in vector and remove it
void Vertex::removeAdjacent(const int v) {
    for (int i = 0; i < adjacents.size(); ++i) {
        if (adjacents[i].getVertexNumber() == v) {
            adjacents.erase(adjacents.begin() + i);
        }
    }
}

std::vector<Vertex> Vertex::getAdjacent() const {
    return adjacents;
}

// Clear all elements in the adjacents vector
void Vertex::clearAdjacent() {
    adjacents.clear();
}

int Vertex::getParent() const {
    return parent;
}

void Vertex::setParent(const int newParent) {
    parent = newParent;
}