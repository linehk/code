// 图 ADT 实现（邻接矩阵）

#include <stdlib.h>
#include "GRAPH.h"

struct graph {
        int V;
        int E;
        int **adj;
}

Graph GRAPHinit(int V)
{
        Graph G = malloc(sizeof *G);
        G->V = V;
        G->E = 0;
        G->adj = MATRIXint(V, V, 0);
        return G;
}

void GRAPHinsertE(Graph G, Edge e)
{
        int v = e.v;
        int w = e.w;

        if (G->adj[v][w] == 0)
        {
                G->E++;
        }
}

void GRAPHremoveE(Graph G, Edge e)
{
        int v = e.v;
        int w = e.w;
        if (G->adj[v][w] == 1) {
                G->E--;
        }
        G->adj[v][w] = 0;
        G->adj[w][v] = 0;
}

int GRAPHedges(Edge a[], Graph G)
{
        int v;
        int w;
        int E = 0;
        for (v = 0; v < G->V; v++) {
                for (w = v + 1; w < G->V; w++) {
                        if (G->adj[v][w] == 1) {
                                a[E++] = EDGE(v, w);
                        }
                }
        }
        return E;
}