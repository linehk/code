// 消环算法

void addflow(link u, int d)
{
        u->flow += d;
        u->dup->flow -= d;
}

int GRAPHmincost(Graph G, int s, int t)
{
        int d;
        int x;
        int w;
        link u;
        link st[maxV];
        GRAPHmaxflow(G, s, t);
        while ((x = GRAPHnegcycle(G, st)) != -1) {
                u = st[x];
                d = Q;
                for (w = u->dup->v; w != x; w = u->dup->v) {
                        u = st[w];
                        d = (Q > d ? d : Q);
                }
                u = st[x];
                addflow(u, d);
                for (w = u->dup->v; w != x; w = u->dup->v) {
                        u = st[w];
                        addflow(u, d);
                }
        }
        return GRAPHcost(G);
}