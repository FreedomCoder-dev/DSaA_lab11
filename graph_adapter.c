//
// Created by Freedom Coder on 16.11.2021.
//

#include "btree.h"
#include "graph_adapter.h"
#include <stdlib.h>
#include <printf.h>

struct TGAdjacencyMatrix *constructTGAMatrix(struct TGEdgeList *edges) {
    struct TGAdjacencyMatrix *matrix = malloc(sizeof(struct TGAdjacencyMatrix));
    matrix->mtx_data = malloc(sizeof(int) * edges->max_node * edges->max_node);
    matrix->node_count = edges->max_node;
    struct TGEdge *tmp = edges->edges;
    for (int i = 0; i < edges->edge_count; ++i) {
        matrix->mtx_data[(tmp->node1 - 1) * matrix->node_count + (tmp->node2 - 1)] = tmp->weight;
        matrix->mtx_data[(tmp->node2 - 1) * matrix->node_count + (tmp->node1 - 1)] = tmp->weight;
        tmp++;
    }
    return matrix;
}

struct TGEdgeList *constructTGEdgeList(struct TGAdjacencyMatrix *matrix) {
    struct TGEdgeList *pList = malloc(sizeof(struct TGEdgeList));
    pList->edge_count = 0;
    int *curr = matrix->mtx_data;
    for (int i = 0; i < matrix->node_count; ++i)
        for (int j = i; j < matrix->node_count; ++j)
            if (matrix->mtx_data[i * matrix->node_count + j])
                pList->edge_count++;
    pList->edges = malloc(sizeof(struct TGEdge) * pList->edge_count);
    pList->max_node = matrix->node_count;
    struct TGEdge *tmp = pList->edges;
    for (int i = 0; i < matrix->node_count; ++i)
        for (int j = i; j < matrix->node_count; ++j) {
            int weight = matrix->mtx_data[i * matrix->node_count + j];
            if (weight) {
                tmp->weight = weight;
                tmp->node1 = i + 1;
                tmp->node2 = j + 1;
                tmp++;
            }
        }
    return pList;
}