// 双向欧拉回路

void dfsReuler(Graph G, Edge e)
{
        link t;
        printf("-%d", e.w);
        pre[e.w] = cnt++;
        for (t = G->adj[e.w]; t != NULL; t = t->next) {
                if (pre[t->v] == -1) {
                        dfsReuler(G, EDGE(e.w, t->v));
                } else if (pre[t->v] < pre[e.v]) {
                        printf("-%d-%d", t->v, e.w);
                }
        }
        if (e.v != e.w) {
                printf("%-%d", e.v);
        } else {
                printf("\n");
        }
}