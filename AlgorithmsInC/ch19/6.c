// 逆拓扑排序（邻接表）

static int cnt0;
static int pre[maxV];

void DAGts(Dag D, int ts[])
{
        int v;
        cnt0 = 0;
        for (v = 0; v < D->V; v++) {
                ts[v] = -1;
                pre[v] = -1
        }
        for (v = 0; v < D->V; v++) {
                if (pre[v] == -1) {
                        TSdfsR(D, v, ts);
                }
        }
}

void TSdfsR(Dag D, int v, int ts[])
{
        link t;
        pre[v] = 0;
        for (t = D->adj[v]; t != NULL; t = t->next) {
                if (pre[t->v] == -1) {
                        TSdfsR(D, t->v, ts);
                }
        }
        ts[cnt0++] = v;
}