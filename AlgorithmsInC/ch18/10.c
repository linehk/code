// 广义图搜索

#define pfs search

void pfs(Graph G, Edge e)
{
        link t;
        int v;
        int w;
        CQput(e);
        pre[e.w] = cnt++;
        while (!CQempty()) {
                e = CQget();
                w = e.w;
                st[w] = e.v;
                for (t = G->adj[w]; t != NULL; t = t->next) {
                        if (pre[v = t->v] == -1) {
                                CQput(EDGE(w, v));
                                pre[v] = cnt++;
                        } else if (st[v] == -1) {
                                CQupdate(EDGE(w, v));
                        }
                }
        }
}