//
// Created by Freedom Coder on 16.11.2021.
//

#ifndef LAB9_GRAPH_ADAPTER_H
#define LAB9_GRAPH_ADAPTER_H

#include "graph.h"

struct TGAdjacencyMatrix* constructTGAMatrix(struct TGEdgeList* edges);
struct TGEdgeList* constructTGEdgeList(struct TGAdjacencyMatrix* edges);

#endif //LAB9_GRAPH_ADAPTER_H
