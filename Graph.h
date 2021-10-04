//
// Created by adries on 2021-04-06.
//

#ifndef MST_GRAPH_H
#define MST_GRAPH_H

#include <list>
#include <vector>
#include "Edge.h"
#include "Vertex.h"

class Graph {
private:
    int numOfVerticies;
    int numOfEdges;
    std::vector<std::vector<Edge>> adjList;
    Vertex* verticies;

public:
    Graph();

    ~Graph();

    // 3 invalid functions to check if an illegal argument was passed

    bool isInvalid(const int u);

    bool isInvalid(const int u, const int v);

    bool isInvalid(const int u, const int v, const double w);

    // Creates a new graph
    void newGraph(const int m);

    // Inserts a new weighted edge between u and v
    void insertEdge(const int u, const int v, const double w);

    // Removes an edge between u and v
    bool eraseEdge(const int u, const int v);

    // Returns the current amount of edges
    int edgeCount() const;

    // Returns the weight of the edge between u and v
    double getWeight(const int u, const int v);

    // Returns the degree of the vertex u
    int degree(int const u) const;

    // Returns whether vertex u and v are adjacent (with the correct weight)
    bool adjacent(const int u, const int v, const double w);

    // Removes all edges from the graph and all of the adjacencies between vertices
    void clear();

    // Calculates the MST using Prim-Jarnik algorithm from the vertex r
    double mst(Vertex r);

};

#endif //MST_GRAPH_H
