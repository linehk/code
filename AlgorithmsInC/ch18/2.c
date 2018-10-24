// 深度优先搜索（邻接表）

void dfsR(Graph G, Edge e)
{
        link t;
        int w = e.w;
        pre[w] = cnt++;
        for (t = G->adj[w]; t != NULL; t = t->next) {
                if (pre[t->v] == -1) {
                        dfsR(G, EDGE(w, t->v));
                }
        }
}