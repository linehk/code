// 图的邻接矩阵表示

#include <stdio.h>
#include <stdlib.h>

main()
{
        int V;
        int i, j, adj[V][V];

        for (i = 0; i < V; i++) {
                for (j = 0; j < V; j++) {
                        adj[i][j] = 0;
                }
        }
        for (i = 0; i < V; i++) {
                adj[i][i] = 1;
        }
        while (scanf("%d %d\n", &i, &j) == 2) {
                adj[i][j] = 1;
                adj[j][i] = 1;
        }
}