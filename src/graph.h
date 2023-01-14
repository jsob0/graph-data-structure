#ifndef GRAPH_DATA_STRUCTURE_H
#define GRAPH_DATA_STRUCTURE_H

#include <stdlib.h>

/* One of the points on which the graph is defined and which may be connected
by graph edges. Vertex can stores more additional data such as personal data. */
struct Vertex {
    int id;
};

/* One of the connections between the nodes (or vertices) of the network. */
struct Edge {
    int src;
    int dst;
};

/* Bipartite Graph. A set of graph vertices decomposed into two disjoint sets
such that no two graph vertices within the same set are adjacent. */
struct Graph {
    struct Vertex *vertices;
    struct Edge *edges;
    size_t n_vertices;
    size_t n_edges;
};

/**
 * Create a new empty graph.
 */
struct Graph *graph_create(void);

/**
 * Release the graph and set to null value.
 */
void graph_release(struct Graph *graph);

/**
 * Add a new empty vertex to the graph with unique id.
 */
int graph_add_vertex(struct Graph *graph, int id);

/**
 * Add a new edge connection between the src and the dst vertex.
 */
int graph_add_edge(struct Graph *graph, int src, int dst);

/**
 * Display the graph.
 */
void graph_display(struct Graph *graph);

#endif /* GRAPH_DATA_STRUCTURE_H */