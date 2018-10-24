// DAG 的传递闭包

void DAGtc(Dag D)
{
        int v;
        D->tc = MATRIXint(D->V, D->V, 0);
        for (v = 0; v < D->V; v++) {
                pre[v] = -1;
        }
        for (v = 0; v < D->V; v++) {
                if (pre[v] == -1) {
                        TCdfsR(D, EDGE(v, v));
                }
        }
}

void TCdfsR(Dag D, Edge e)
{
        int u;
        int i;
        int v = e.w;
        pre[v] = cnt++;
        for (u = 0; u < G->V; u++) {
                if (D->adj[v][u] != 0) {
                        D->tc[v][u] = 1;
                        if (pre[u] > pre[v]) {
                                continue;
                        }
                        if (pre[u] == -1) {
                                TCdfsR(D, EDGE(v, u));
                        }
                        for (i = 0; i < G->V; i++) {
                                if (D->tc[u][i] == 1) {
                                        D->tc[v][i] = 1;
                                }
                        }
                }
        }
}

int DAGreach(Dag D, int s, int t)
{
        return D->tc[s][t];
}