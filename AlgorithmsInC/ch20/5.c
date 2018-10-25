// Kruskal MST 算法

void GRAPHmstE(Graph G, Edge mst[])
{
        int i;
        int k;
        Edge a[maxE];
        int E = GRAPHedges(a, G);
        sort(a, 0, E - 1);
        UFinit(G->V);
        for (i = 0, k = 0; i < E && k < G->V - 1; i++) {
                if (!UFfind(a[i].v, a[i].w)) {
                        UFunion(a[i].v, a[i].w);
                        mst[k++] = a[i];
                }
        }
}