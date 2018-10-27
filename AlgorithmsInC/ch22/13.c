// 网络单纯形（改进实现）

int R(link st[], link u)
{
        return u->cost - phiR(st, u->dup->v) + phiR(st, u->v);
}

int GRAPHmincost(Graph G, int s, int t)
{
        int v;
        int old = 0;
        link u;
        link x;
        link st[maxV];
        GRAPHinsertE(G, EDGE(s, t, M, M, C));
        initialize(G, s, t, st);
        for (valid = 1; valid != old; old = valid) {
                for (v = 0; v < G->V; v++) {
                        for (u = G->adj[v]; u != NULL; u = u->next) {
                                if ((Q > 0) && (R(st, u) < 0)) {
                                        update(st, augment(st, u), u);
                                        valid++;
                                }
                        }
                }
        }
        return GRAPHcost(G);
}