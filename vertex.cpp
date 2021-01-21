#include "vertex.h"
#include "edge.h"

Vertex::Vertex(std::string key) : key(key) {
    color = white;
}

Vertex::~Vertex() {
    // no mem allcoation happening in class
}

bool Vertex::operator==(const Vertex& v) const {
    return key == v.key;
}

bool Vertex::operator!=(const Vertex& v) const {
    return key != v.key;
}

//delete this
std::string Vertex::get_key() const {
    return key;
}

void Vertex::add_edge(Edge e) {
    edges.push_back(e);
}

void Vertex::remove_edge(Edge e) {
    edges.remove(e);
}

// backwards edges are not real edges in the graph. Just an easy way of keeping
// track of who is pointing at a vertex
void Vertex::add_backwards_edge(Edge e) {
    backwards_edges.push_back(e);
}

void Vertex::remove_backwards_edge(Edge e) {
    backwards_edges.remove(e);
}

bool Vertex::is_neighbor(const Vertex& v) {
    for (std::list<Edge>::iterator it = edges.begin(); it != edges.end();
         it++) {
        if (*it->dest == v)
            return true;
    }
    return false;
}

 int Vertex::n_neighbors() {
    return edges.size();
}

// bool Vertex::path_exists(Vertex* v) {  // called destinationExists in docs...?
//    // do some algorithm
//}

void Vertex::print() {
    // what format do they want?
    std::cout << key << std::endl;
}
