//
// Created by adries on 2021-04-07.
//

#ifndef MST_VERTEX_H
#define MST_VERTEX_H

#include <vector>

class Vertex{
private:
    int vertexNumber; // The number representing the vertex
    double key; // The key of the vertex
    int parent; // The parent of the vertex
    std::vector<Vertex> adjacents; // The adjacent vertices

public:
    Vertex();

    Vertex(const int vertNum);

    // Getter functions

    int getParent() const;
    double getKey() const;
    int getVertexNumber() const;

    // Setter functions

    void setVertexNumber(const int newVertexNumber);
    void setKey(const double newKey);
    void setParent(const int newParent);

    // Functions for adjacents

    std::vector<Vertex> getAdjacent() const;
    void addAdjacent(const int v);
    void removeAdjacent(const int v);
    void clearAdjacent();

};

#endif //MST_VERTEX_H
