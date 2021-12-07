#include <stdio.h>
#include "graph_reader.h"
#include "graph_adapter.h"
#include "queue.h"


void resolve_component(struct TGAdjacencyMatrix *mtx, int start_vtx, int *marks) {
    struct Queue *queue = F_MakeQueue();
    enQueue(queue, start_vtx);

    int counter_before = 1, counter_after = 0;
    int curr_mark = 1;

    int (*matrix)[mtx->node_count] = (int (*)[mtx->node_count]) mtx->mtx_data;

    marks[start_vtx] = curr_mark++;

    while (!Qempty(queue)) {
        int vtx = deQueue(queue);
        for (int i = 0; i < mtx->node_count; ++i)
            if (!marks[i] && matrix[vtx][i]) {
                enQueue(queue, i);
                counter_after++;
                marks[i] = curr_mark;
            }
        if (!--counter_before) {
            counter_before = counter_after;
            curr_mark++;
            counter_after = 0;
        }
    }

    free(queue);
}

int arr_first_empty(int *arr, int count) {
    int id = 0;
    while (*arr++ && count--) ++id;
    return id;
}

void printAdjMatrix(struct TGAdjacencyMatrix *mtx) {
    printf("%d\n", mtx->node_count);
    int* mtx_end = mtx->mtx_data+mtx->node_count*mtx->node_count;
    for (int* i = mtx->mtx_data; i < mtx_end; ++i) {
        if ((i != mtx->mtx_data) && (i - mtx->mtx_data) % mtx->node_count == 0)
            printf("\n");
        printf("%d ", *i);
    }
    printf("\n");
}

int main() {
//    struct TGEdge a = {4, 7, 1};
//    struct TGEdge b = {5, 9, 1};
//    printf("%d %d", compareEdgess(&a,&b), compareEdgess(&b,&a));

    struct TGEdgeList *edges, *e2;

    FILE *in = fopen("../in.txt", "r");
    edges = readTGEdgeList(in);
    fclose(in);
    struct TGAdjacencyMatrix *mtx = constructTGAMatrix(edges);
    //printAdjMatrix(mtx);
    int *marks = malloc(sizeof(int) * mtx->node_count);
    for (int i = 0; i < mtx->node_count; ++i) {
        marks[i] = 0;
    }

    resolve_component(mtx, 0, marks);

    for (int i = 0; i < mtx->node_count; ++i) {
        printf("%d %d\n", i+1, marks[i]);
    }

    return 0;
}
