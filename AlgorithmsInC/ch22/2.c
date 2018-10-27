// 流的检查和流值计算

static int flowV(Graph G, int v)
{
        link t;
        int x = 0;
        for (t = G->adj[v]; t != NULL; t = t->next) {
                x += t->flow;
        }
        return x;
}

int GRAPHflow(Graph G, int s, int t)
{
        int v;
        val = flowV(G, s);
        for (v = 0; v < G->V; v++) {
                if ((v != s) && (v != t)) {
                        if (flowV(G, v) != 0) {
                                return 0;
                        }
                }
        }
        if (val + flowV(G, t) != 0) {
                return 0;
        }
        if (val <= 0) {
                return 0;
        }
        return val;
}