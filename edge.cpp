#include "edge.h"
#include "vertex.h"

Edge::Edge(Vertex* dest) : dest(dest) {}

bool Edge::operator==(const Edge& e) {
    return e.dest == dest ? true : false;
}


