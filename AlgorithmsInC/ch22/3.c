// 增大路径最大流实现

static int wt[maxV];
#define Q (u->cap < 0 ? -u->flow : u->cap - u->flow)

int GRAPHpfs(Graph G, int s, int t, link st[])
{
        int v;
        int w;
        int d = M;
        link u;
        PQinit();
        priority = wt;
        for (v = 0; v < G->V; v++) {
                st[v] = NULL;
                wt[v] = 0;
                PQinsert(v);
        }
        wt[s] = M;
        PQinc(s);
        while (!PQempty()) {
                v = PQdelmax();
                if ((wt[v] == 0) || (v == t)) {
                        break;
                }
                for (u = G->adj[v]; u != NULL; u = u->next) {
                        if (Q > 0) {
                                if (P > wt[w = u->v]) {
                                        wt[w] = P;
                                        PQinc(w);
                                        st[w] = u;
                                }
                        }
                }
                wt[v] = M;
        }
        if (wt[t] == 0) {
                return 0;
        }
        for (w = t; w != s; w = st[w]->dup->v) {
                u = st[w];
                d = (Q > d ? d : Q);
        }
        return d;
}

void GRAPHmaxflow(Graph G, int s, int t)
{
        int x;
        int d;
        link st[maxV];
        while ((d = GRAPHpfs(G, s, t, st)) != 0) {
                for (x = t; x != s; x = st[x]->dup->v) {
                        st[x]->flow += d;
                        st[x]->dup->flow -= d;
                }
        }
}