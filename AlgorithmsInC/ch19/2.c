// 有向图的 DFS

void dfsR(Graph G, EDGE e)
{
        link t;
        int i;
        int v;
        int w = e.w;
        Edge x;
        show("tree", e);
        pre[w] = cnt++;
        for (t = G->adj[w]; t != NULL; t = t->next) {
                if (pre[t->v] == -1) {
                        dfsR(G, EDGE(w, t->v));
                } else {
                        v = t->v;
                        x = EDGE(w, v);
                        if (post[v] == -1) {
                                show("back", x);
                        } else if (pre[v] > pre[w]) {
                                show("down", x);
                        } else {
                                show("cross", x);
                        }
                }
        }
        post[w] = cntP++;
}