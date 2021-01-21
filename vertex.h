#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>
#include <list>
#include <string>

class Edge;

enum Color { white, grey, black };

class Vertex {
    friend class Graph;
    friend class Vertex_Compare;

public:
    Vertex(std::string key = "");
    ~Vertex();
    bool operator==(const Vertex& v) const;
    std::string get_key() const;
    void add_edge(Edge e);
    void remove_edge(Edge e);
    void add_backwards_edge(Edge e);
    void remove_backwards_edge(Edge e);
    bool is_neighbor(const Vertex& v);
    int n_neighbors();
    void print();

private:
    std::string key;
    Color color;
    std::list<Edge> edges;
    std::list<Edge> backwards_edges;  // backwards edges don't actually exist!!
};

#endif
