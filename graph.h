//
// Created by Freedom Coder on 16.11.2021.
//

#ifndef LAB9_GRAPH_H
#define LAB9_GRAPH_H

struct TGAdjacencyMatrix
{
    int* mtx_data;
    int node_count;
};

struct TGEdge
{
    int node1;
    int node2;
    int weight;
};

struct TGEdgeList {
    struct TGEdge *edges;
    int edge_count;
    int max_node;
};

#endif //LAB9_GRAPH_H
