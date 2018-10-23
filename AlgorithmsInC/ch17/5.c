// 图 ADT 输出（邻接表格式）

void GRAPHshow(Graph G)
{
        int i;
        int j;
        printf("%d vertices, %d edges\n", G->V, G->E);
        for (i = 0; i < G->V; i++) {
                printf("%2d:", i);
                for (j = 0; j < G->V; j++) {
                        if (G->adj[i][j] == 1) {
                                printf(" %2d", j);
                        }
                }
                printf("\n");
        }
}