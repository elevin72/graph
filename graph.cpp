#include "graph.h"
#include <string>
#include "edge.h"
#include "vertex.h"

Graph::Graph() {}

Graph::~Graph() {}

bool Graph::add_vertex(const std::string& s) {
    if (vertices.count(s)) {
        return false;
    } else {
        vertices.insert({s, Vertex(s)});  // should work in theory
        return true;
    }
}

bool Graph::remove_vertex(const std::string& s) {
    if (!vertices.count(s))
        return false;
    else {
        // remove all edges from and to this vertex
        // This is where you need list of edges pointing *to* vertex!
        /* Vertex *goner = &vertices[s];  // everything onwards from here is
         * trash */
        Vertex temp_vertex(s);
        Edge temp_edge(&temp_vertex);
        for (std::list<Edge>::iterator it = vertices[s].backwards_edges.begin();
             it != vertices[s].backwards_edges.end();
             it++) {
            it->dest->remove_edge(temp_edge);
        }
        // finally delete the vertex
        vertices.erase(s);
        return true;
    }
}

bool Graph::add_edge(const std::string& source, const std::string& dest) {
    if (!vertices.count(source))
        return false;
    else if (!vertices.count(dest))
        return false;
    else if (vertices[source].is_neighbor(vertices[dest]))
        return false;
    else {
        vertices[source].add_edge(Edge(&vertices[dest]));
        vertices[dest].add_backwards_edge(Edge(&vertices[source]));
        return true;
    }
}

bool Graph::remove_edge(const std::string& source, const std::string& dest) {
    if (!vertices.count(source))
        return false;
    else if (!vertices.count(dest))
        return false;
    else if (!vertices[source].is_neighbor(vertices[dest]))
        return false;
    else {
        vertices[source].remove_edge(Edge(&vertices[dest]));
        vertices[dest].remove_backwards_edge(Edge(&vertices[dest]));
        return true;
    }
}

bool Graph::print_neighbors_from(const std::string& s) {
    if (!vertices.count(s))
        return false;
    Vertex& v = vertices[s];
    for (std::list<Edge>::iterator it = v.edges.begin(); it != v.edges.end();
         it++) {
        it->dest->print();
        std::cout << " ";
    }
    return true;
}

bool Graph::print_neighbors_to(const std::string& s) {
    if (!vertices.count(s))
        return false;
    Vertex& v = vertices[s];
    for (std::list<Edge>::iterator it = v.backwards_edges.begin();
         it != v.backwards_edges.end();
         it++) {
        it->dest->print();
        std::cout << " ";
    }
    return true;
}

bool Graph::print_reachable_from(const std::string& s) {
    if (!vertices.count(s))
        return false;
    // first intitialize map to be "unread"
    for (std::map<std::string, Vertex>::iterator it = vertices.begin();
         it != vertices.end();
         it++) {
        it->second.color = white;
    }
    // now do BFS
    Vertex* cur;
    std::list<Vertex*> queue;
    vertices[s].color = grey;
    queue.push_back(&vertices[s]);
    while (!queue.empty()) {
        cur = queue.front();
        cur->print();
        std::cout << " ";
        for (std::list<Edge>::iterator it = cur->edges.begin();
             it != cur->edges.end();
             it++) {
            if (it->dest->color == white) {
                it->dest->color = grey;
                queue.push_back(it->dest);
            }
        }
        cur->color = black;
        queue.pop_front();
    }
    return true;
}

void Graph::print() {
    for (std::map<std::string, Vertex>::iterator it = vertices.begin();
         it != vertices.end();
         it++) {
        it->second.print();
        std::cout << ": ";
        for (std::list<Edge>::iterator jt = it->second.edges.begin();
             jt != it->second.edges.end();
             jt++) {
            jt->dest->print();
            std::cout << " ";
        }
        std::cout << "\n";
    }
}
