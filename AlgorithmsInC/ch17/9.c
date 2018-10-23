// 由符号对构建一个图

#include <stdio.h>
#include "GRAPH.h"
#include "ST.h"

Graph GRAPHscan(int Vmax, int Emax)
{
        char v[100];
        char w[100];
        Graph G = GRAPHinit(Vmax);
        STinit();
        while (scanf("%99s %99s", v, w) == 2) {
                GRAPHinsertE(G, EDGE(STindex(v), STindex(w)));
        }
        return G;
}