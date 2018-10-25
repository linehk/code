// 加权图 ADT（邻接矩阵）

#include <stdlib.h>
#include "GRAPH.h"
struct graph {
        int V;
        int E;
        double **adj;
};

Graph GRAPHinit(int V)
{
        int v;
        Graph G = malloc(sizeof *G);
        G->adj = MATRIXint(V, V, maxWT);
        G->V = V;
        G->E = 0;
        return G;
}

void GRAPHinsertE(Graph G, Edge e)
{
        if (G->adj[e.v][e.w] == maxWT) {
                G->E++;
        }
        G->adj[e.v][e.w] = e.wt;
        G->adj[e.w][e.v] = e.wt;
}
