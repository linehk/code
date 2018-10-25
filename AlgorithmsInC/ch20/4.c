// 优先级优先搜索（邻接表）

#define GRAPHpfs GRAPHmst

static int fr[maxV];
static double *priority;
int less(int i, int j)
{
        return priority[i] < priority[j];
}

#define P t->wt

void GRAPHpfs(Graph G, int st[], double wt[])
{
        link t;
        int v;
        int w;
        PQinit();
        priority = wt;
        for (v = 0; v < G->V; v++) {
                st[v] = -1;
                fr[v] = -1;
        }
        fr[0] = 0;
        PQinsert(0);
        while (!PQempty()) {
                v = PQdelmin();
                st[v] = fr[v];
                for (t = G->adj[v]; t != NULL; t = t->next) {
                        if (fr[w = t->v] == -1) {
                                wt[w] = P;
                                PQinsert(w);
                                fr[w] = v;
                        } else if ((st[w] == -1) && (P < wt[w])) {
                                wt[w] = P;
                                PQdec(w);
                                fr[w] = v;
                        }
                }
        }
}