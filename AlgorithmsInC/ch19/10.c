// 强分量（Kosaraju 算法）

static int post[maxV];
static int postR[maxV];
static int cnt0;
static int cnt1;
void SCdfsR(Graph G, int w)
{
        link t;
        G->sc[w] = cnt1;
        for (t = G->adj[w]; t != NULL; t = t->next) {
                if (G->sc[t->v] == -1) {
                        SCdfsR(G, t->v);
                }
        }
        post[cnt0++] = w;
}

int GRAPHsc(Graph G)
{
        int v;
        Graph R;
        R = GRAPHreverse(G);
        cnt0 = 0;
        cnt1 = 0;
        for (v = 0; v < G->V; v++) {
                G->sc[v] = -1;
        }
        for (v = 0; v < G->V; v++) {
                postR[v] = post[v];
        }
        for (v = G->V - 1; v >= 0; v--) {
                if (G->sc[postR[v]] == -1) {
                        SCdfsR(G, postR[v]);
                        cnt1++;
                }
        }
        GRAPHdestory(R);
        return cnt1;
}

int GRAPHstrongreach(Graph G, int s, int t)
{
        return G->sc[s] == G->sc[t];
}