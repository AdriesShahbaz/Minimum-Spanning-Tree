//
// Created by adries on 2021-04-06.
//

#include "Graph.h"
#include "illegal_exception.h"
#include <iostream>
#include "MinPQ.h"
#include <iomanip>
#include <cmath>

Graph::Graph() {
    // Start with no vertices or edges

    numOfVerticies = 0;
    numOfEdges = 0;
}

// Checks if u is not in valid range
bool Graph::isInvalid(const int u) {
    if (u >= numOfVerticies || u < 0) {
        return true;
    }
    return false;
}

// Checks if u and v are not in valid range
bool Graph::isInvalid(const int u, const int v) {
    if ((u >= numOfVerticies || u < 0) || (v >= numOfVerticies || v < 0) || (u == v)) {
        return true;
    }
    return false;
}

// Checks if u and v are not in valid range and if weight is greater than 0
bool Graph::isInvalid(const int u, const int v, const double w) {
    if ((u >= numOfVerticies || u < 0) || (v >= numOfVerticies || v < 0) || (u == v) || (w <= 0.00)) {
        return true;
    }
    return false;
}

// Returns number of edges
int Graph::edgeCount() const {
    return numOfEdges;
}

// Returns degree of a vertex
int Graph::degree(int const u) const {
    return adjList[u].size();
}

void Graph::newGraph(const int m) {
    // Set number of vertices of the graph
    numOfVerticies = m;

    // Resize the adjList vertex to match this number of vertices
    adjList.resize(numOfVerticies);

    // Create an array of vertices
    verticies = new Vertex[numOfVerticies];

    // Assign values to the vertices
    for (int i = 0; i < numOfVerticies; i++) {
        verticies[i] = Vertex(i);
    }
}

bool Graph::adjacent(const int u, const int v, const double w) {
    if (isInvalid(u, v, w)) {
        throw illegal_exception("illegal argument");
    }

    bool isFound = false;

    // Check to see if there is an edge between u and v with weight w
    for (int i = 0; i < adjList[u].size(); i++) {
        if ((adjList[u][i].getDestVertex() == v) && adjList[u][i].getWeight() == w) {
            isFound = true;
            break;
        }
    }

    return isFound;
}

void Graph::clear() {
    // Remove all edges and adjacincies
    for (int i = 0; i < numOfVerticies; i++) {
        adjList[i].clear();
        verticies[i].clearAdjacent();
    }
    numOfEdges = 0;
}

double Graph::getWeight(const int u, const int v) {
    // Find the weight of edge between u and v
    for (int i = 0; i < adjList[u].size(); i++) {
        if (adjList[u][i].getDestVertex() == v) {
            return adjList[u][i].getWeight();
        }
    }
    return 0.0;
}

void Graph::insertEdge(const int u, const int v, const double w) {
    if (isInvalid(u, v, w)) {
        throw illegal_exception("illegal argument");
    }

    // If the edge between u and v already exists, remove it
    // to allow it to be replaced
    for (int i = 0; i < adjList[u].size(); i++) {
        if (adjList[u][i].getDestVertex() == v) {
            eraseEdge(u, v);
            verticies[u].removeAdjacent(v);
            verticies[v].removeAdjacent(u);
        }
    }

    Edge tmp1 = Edge(u, w);
    Edge tmp2 = Edge(v, w);
    adjList[u].push_back(tmp2);
    verticies[u].addAdjacent(v);
    adjList[v].push_back(tmp1);
    verticies[v].addAdjacent(u);

    numOfEdges += 2;

    std::cout << "success" << std::endl;
}

bool Graph::eraseEdge(const int u, const int v) {
    if (isInvalid(u, v)) {
        throw illegal_exception("illegal argument");
    }

    bool isEdge = false;

    // Find the edge between u and v and remove it
    // also remove the adjacency between u and v
    for (int i = 0; i < adjList[u].size(); i++) {
        if (adjList[u][i].getDestVertex() == v) {
            adjList[u].erase(adjList[u].begin() + i);
            numOfEdges--;
            verticies[u].removeAdjacent(v);
            isEdge = true;
            break;
        }
    }

    // Same for v and u
    for (int i = 0; i < adjList[v].size(); i++) {
        if (adjList[v][i].getDestVertex() == u) {
            adjList[v].erase(adjList[v].begin() + i);
            numOfEdges--;
            verticies[v].removeAdjacent(u);
            break;
        }
    }

    return isEdge;

}

double Graph::mst(Vertex r) {
    if (isInvalid(r.getVertexNumber())) {
        throw illegal_exception("illegal argument");
    }

//    // If any of the vertices have no edges, return -1 (indicates not connected)
//    for (int i = 0; i < numOfVerticies; i++) {
//        if (adjList[i].size() == 0) {
//            return -1;
//        }
//    }

    // Array to track the key value of every vertex
    double key[numOfVerticies];

    // Set the key values to INFINITY
    for (int i = 0; i < numOfVerticies; i++) {
        verticies[i].setKey(INFINITY);
        key[i] = INFINITY;
    }

    double totalWeight = 0.0;

    // Initialize Min PQ
    MinPQ Q(verticies, numOfVerticies);

    // Set root key to 0
    Q.modifyKey(r.getVertexNumber(), 0);

    key[r.getVertexNumber()] = 0;

    // While PQ is not empty
    while (!Q.isEmpty()) {
        // Extract the smallest element from the PQ
        Vertex u = Q.extractMin();
        // For every adjacent vertex to u
        for (Edge v : adjList[u.getVertexNumber()]) {
            // Get the weight between u and v
            double weight = v.getWeight();

            // If any of the vertices have no edges, return -1 (indicates not connected)
            if (u.getKey() == INFINITY) {
                return -1;
            }

            // If that weight is less than the current value and the vertex
            // is still in the PQ
            if ((Q.isInPQ(v.getDestVertex())) && (weight < key[v.getDestVertex()])) {
                // Update the key value with the new weight
                key[v.getDestVertex()] = weight;
                Q.modifyKey(v.getDestVertex(), weight);
            }
        }
    }

    // Add up all of the weights
    for (int i = 0; i < numOfVerticies; i++) {
        totalWeight += key[i];
    }

    return totalWeight;
}


Graph::~Graph() {
    delete []verticies;
}