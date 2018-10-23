//  线性时间欧拉路径（邻接表）

#include "STACK.h"

int path(Graph G, int v)
{
        int w;
        for (; G->adj[v] != NULL; v = w) {
                STACKpush(v);
                w = G->adj[v]->v;
                GRAPHremoveE(G, EDGE(v, w));
        }
        return v;
}

void pathEshow(Graph G, int v, int w)
{
        STACKinit(G->E);
        printf("%d", w);
        while ((path(G, v) == v) && !STACKempty()) {
                v = STACKpop();
                printf("-%d", v);
        }
        printf("\n");
}