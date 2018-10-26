// 作业调度

#include <stdio.h>
#include "GRAPH.h"
#define Nmax 1000
main(int argc, char *argv[])
{
        int i;
        int s;
        int t;
        int N = atoi(argv[1]);
        double length[Nmax];
        double start[Nmax];
        int st[Nmax];
        Graph G = GRAPHinit(N);
        for (i = 0; i < G->V; i++) {
                scanf("%lf", &length[i]);
        }
        while (scanf("%d %d", &s, &t) != EOF) {
                GRAPHinsertE(G, EDGE(s, t, length[s]));
        }
        Graphlpt(G, 0, st, start);
        for (i = 0; i < G->V; i++) {
                printf("%3d %6.2f\n", i, start[i]);
        }
}