// 经由归约到最大流的二分匹配

#include <stdio.h>
#include "GRAPH.h"

main(int argc, char *argv[])
{
        Graph G;
        int i;
        int v;
        int w;
        int E;
        int V = atoi(argv[1]);
        G = GRAPHinit(2 * V + 2);
        for (i = 1; i <= V; i++) {
                GRAPHinsertE(G, EDGE(0, i, 1, 0));
        }
        while (scanf("%d %d", &v, &w) != EOF) {
                GRAPHinsertE(G, EDGE(v, w, 1, 0));
        }
        for (i = V + 1; i <= V + V; i++) {
                GRAPHinsertE(G, EDGE(i, V + V + 1, 1, 0));
        }
        if (GRAPHmaxflow(G, 0, V + V + 1) == 0) {
                return;
        }
        E = GRAPHedges(a, G);
        for (i = 0; i < G->V; i++) {
                if ((a[i].v != 0) && (a[i].w != V + V + 1)) {
                        if (a[i].flow == 1) {
                                printf("%d-%d\n", a[i].v, a[i].w);
                        }
                }
        }
}