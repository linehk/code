// 加权图 ADT（邻接表）

#include "GRAPH.h"
typedef struct node *link;
struct node {
        int v;
        double wt;
        link next;
};
struct graph {
        int V;
        int E;
        link *adj;
};

link NEW(int v, double wt, link next)
{
        link x = malloc(sizeof *x);
        x->v = v;
        x->wt = wt;
        x->next = next;
        return x;
}

Graph GRAPHinit(int V)
{
        int i;
        Graph G = malloc(sizeof *G);
        G->adj = malloc(V * sizeof(link));
        G->V = V;
        G->E = 0;
        for (i = 0; i < V; i++) {
                G->adj[i] = NULL;
        }
        return G;
}

void GRAPHinsertE(Graph G, Edge e)
{
        link t;
        int v = e.v;
        int w = e.w;
        if (v == w) {
                return;
        }
        G->adj[v] = NEW(w, e.wt, G->adj[v]);
        G->adj[w] = NEW(v, e.wt, G->adj[w]);
        G->E++;
}