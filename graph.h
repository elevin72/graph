#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
#include <map>
#include <string>

class Edge;
class Vertex;

class Graph {
public:
    Graph();
    ~Graph();
    /* void add_edge(Edge* e); */
    /* int n_neighbors(); */
    /* bool path_exists(Vertex* v);  // called destinationExists in docs...? */

    bool add_vertex(const std::string& s);  // new vertex not connected
    bool add_edge(const std::string& source, const std::string& dest);
    bool remove_vertex(const std::string& s);
    bool remove_edge(const std::string& source, const std::string& dest);
    bool print_neighbors_from(const std::string& s);
    bool print_neighbors_to(const std::string& s);
    bool print_reachable_from(const std::string& s);
    void print();

private:
    std::map<std::string, Vertex> vertices;
    void print_vertices(std::list<Vertex>);
};

#endif
