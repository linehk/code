// 拓扑排序（邻接矩阵）

void TSdfsR(Dag D, int v, int ts[])
{
        int w;
        pre[v] = 0;
        for (w = 0; w < D->V; w++) {
                if (D->adj[w][v] != 0) {
                        if (pre[v] == -1) {
                                TSdfsR(D, w, ts);
                        }
                }
        }
        ts[cnt0++] = v;
}