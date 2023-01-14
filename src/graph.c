#include "graph.h"

#include <stdio.h>

struct Graph *graph_create(void) {
    // If we set a NULL value for the variable to be dynamically allocated at
    // the beginning, we can check whether the allocation succeeded.
    struct Graph *graph = NULL;

    // Allocate memory space for a new graph structure and error exception
    // handling for this allocation.
    graph = (struct Graph *)malloc(sizeof(struct Graph));
    if (NULL == graph)
        return NULL;

    // Initialize the variables.
    graph->vertices = NULL;
    graph->edges = NULL;
    graph->n_vertices = 0;
    graph->n_edges = 0;

    return graph;
}

void graph_release(struct Graph *graph) {
    // Check if the passed graph is not NULL.
    if (NULL == graph)
        return;

    free(graph->vertices);
    free(graph->edges);
    free(graph);
}

int graph_add_vertex(struct Graph *graph, int id) {
    struct Vertex *tmp_vertices = NULL;

    // Reallocate memory space for a new vertices array structure and error
    // exception handling for this allocation.
    tmp_vertices = (struct Vertex *)realloc(graph->vertices, 
        sizeof(struct Vertex) * ++graph->n_vertices);
    if (NULL == tmp_vertices)
        // Returns one, which means that an error has occurred.
        return 1;

    tmp_vertices[graph->n_vertices - 1].id = id;
    graph->vertices = tmp_vertices;

    return 0;
}

int graph_add_edge(struct Graph *graph, int src, int dst) {
    struct Edge *tmp_edges = NULL;

    // Reallocate memory space for a new edges array structure and error
    // exception handling for this allocation.
    tmp_edges = (struct Edge *)realloc(graph->edges, 
        sizeof(struct Edge) * ++graph->n_edges);
    if (NULL == tmp_edges)
        // Returns one, which means that an error has occurred.
        return 1;

    tmp_edges[graph->n_edges - 1].src = src;
    tmp_edges[graph->n_edges - 1].dst = dst;
    graph->edges = tmp_edges;

    return 0;
}

void graph_display(struct Graph *graph) {
    // Check if the passed graph is not NULL.
    if (NULL == graph)
        return;

    for (size_t i = 0; i < graph->n_edges; i++)
        printf("%d -> %d\n", graph->edges[i].src, graph->edges[i].dst);
}