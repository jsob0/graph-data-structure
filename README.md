# Graph Data Structure
Simple graph data structure.

## What is a graph data structure and where is it used?
A graph data structure is a collection of vertices (also called nodes) and edges that connect the vertices. The edges represent relationships or connections between the vertices. Graphs can be represented in different ways, such as by an adjacency list or an adjacency matrix.

Graphs can be used to represent many types of real-world problems and systems, such as networks (e.g., social networks, road networks, electrical networks), mathematical problems (e.g., solving equations, mapping optimization problems), and many other types of problems and systems. Graphs are widely used in computer science, mathematics, and engineering, as well as in many other fields such as biology, physics, and social sciences.

![](./doc/dark-graph-structure.png#gh-dark-mode-only)
![](./doc/light-graph-structure.png#gh-light-mode-only)

## Example of simple code
Create a new empty graph structure add vertices (nodes) to it and connect them with edges.
```c
#include "graph.h"

int main(int argc, char **argv) {

    struct Graph *graph = graph_create();

    graph_add_vertex(graph, 0);
    graph_add_vertex(graph, 1);
    graph_add_vertex(graph, 2);

    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 2, 1);
    graph_add_edge(graph, 2, 0);
    graph_add_edge(graph, 1, 2);

    graph_display(graph);

    graph_release(graph);
    return 0;
}
```

## Getting the source
Download the source code by running the following code in your command prompt:
```sh
$ git clone https://github.com/jsob0/graph-data-structure.git
```
or simply [grab](https://github.com/jsob0/graph-data-structure/archive/main.zip) a copy of the source code as a Zip file.

## License
The code is released under the MIT License. See [LICENSE](/LICENSE).