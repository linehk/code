// 图搜索

static int cnt;
static int pre[maxN];
void GRAPHsearch(Graph G)
{
        int v;
        cnt = 0;
        for (v = 0; v < G->V; v++) {
                pre[v] = -1;
        }
        for (v = 0; v < G->V; v++) {
                if (pre[v] == -1) {
                        search(G, EDGE(v, v));
                }
        }
}
