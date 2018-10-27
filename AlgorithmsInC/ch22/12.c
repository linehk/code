// 网络单纯形（基本实现）

#define R(u) u->cost - phi[u->dup->v] + phi[u->v]

void addflow(link u, int d)
{
        u->flow += d;
        u->dup->flow -= d;
}

int GRAPHmincost(Graph G, int s, int t)
{
        int v;
        link u;
        link x;
        link st[maxV];
        GRAPHinsertE(G, EDGE(s, t, M, M, C));
        initialize(G, s, t, st);
        for (valid = 1; valid++; ) {
                for (v = 0; v < G->V; v++) {
                        phi[v] = phiR(st, v);
                }
                for (v = 0, x = G->adj[v]; v < G->V; v++) {
                        for (u = G->adj[v]; u != NULL; u = u->next) {
                                if (Q > 0) {
                                        if (R(u) < R(x)) {
                                                x = u;
                                        }
                                }
                        }
                }
                if (R(x) == 0) {
                        break;
                }
                update(st, augment(st, x), x);
        }
        return GRAPHcost(G);
}