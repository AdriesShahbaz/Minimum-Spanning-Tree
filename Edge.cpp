//
// Created by adries on 2021-04-06.
//

#include "Edge.h"

Edge::Edge(const int dest, const double wt) {
    destVertex = dest;
    weight = wt;
}

int Edge::getDestVertex() const {
    return destVertex;
}

double Edge::getWeight() const {
    return weight;
}