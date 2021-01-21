#ifndef EDGE_H
#define EDGE_H

class Vertex;

class Edge {
    friend class Vertex;
    friend class Graph;

public:
    Edge(Vertex* dest);
    bool operator==(const Edge& e);

private:
    Vertex* dest;
};

#endif
