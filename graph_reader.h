//
// Created by Freedom Coder on 16.11.2021.
//

#ifndef LAB9_GRAPH_READER_H
#define LAB9_GRAPH_READER_H

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct TGAdjacencyMatrix* readTGAMatrix(FILE* file);
struct TGEdgeList* readTGEdgeList(FILE* file);

#endif //LAB9_GRAPH_READER_H
