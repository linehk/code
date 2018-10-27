// 流网络 ADT 实现

#include <stdlib.h>
#include "GRAPH.h"
typedef struct node *link;
struct node {
        int v;
        int cap;
        int flow;
        link dup;
        link next;
};
struct graph {
        int V;
        int E;
        link *adj;
};

link NEW(int v, int cap, int flow, link next)
{
        link x = malloc(sizeof *x);
        x->v = v;
        x->cap = cap;
        x->flow = flow;
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
        int v = e.v;
        int w = e.w;
        G->adj[v] = NEW(w, e.cap, e.flow, G->adj[v]);
        G->adj[w] = NEW(v, -e.cap, -e.flow, G->adj[w]);
        G->adj[v]->dup = G->adj[w];
        G->adj[w]->dup = G->adj[v];
        G->E++;
}