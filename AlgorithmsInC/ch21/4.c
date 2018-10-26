// 所有对最短路径的 Dijkstra 算法

static int st[maxV];
static double wt[maxV];
void GRAPHspALL(Graph G)
{
        int v;
        int w;
        Graph R = GRAPHreverse(G);
        G->dist = MATRIXdouble(G->V, G->V, maxWT);
        G->path = MATRIXint(G->V, G->V, G->V);
        for (v = 0; v < G->V; v++) {
                GRAPHpfs(R, v, st, wt);
                for (w = 0; w < G->V; w++) {
                        G->dist[w][v] = wt[w];
                }
                for (w = 0; w < G->V; w++) {
                        if (st[w] != -1) {
                                G->path[w][v] = st[w];
                        }
                }
        }
}

double GRAPHspDIST(Graph G, int s, int t)
{
        return G->dist[s][t];
}

int GRAPHspPATH(Graph G, int s, int t)
{
        return G->path[s][t];
}