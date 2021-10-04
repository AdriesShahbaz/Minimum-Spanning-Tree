//
// Created by adries on 2021-04-06.
//

#ifndef MST_EDGE_H
#define MST_EDGE_H

class Edge{
private:
    int destVertex;
    double weight;

public:
    Edge(const int dest, const double wt);

    int getDestVertex() const;
    double getWeight() const;
};



#endif //MST_EDGE_H
