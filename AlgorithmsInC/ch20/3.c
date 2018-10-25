// Prim 算法

static int fr[maxV];
#define P G->adj[v][w]
void GRAPHmstV(Graph G, int st[], double wt[])
{
        int v;
        int w;
        int min;
        for (v = 0; v < G->V; v++) {
                st[v] = -1;
                fr[v] = v;
                wt[v] = maxWT;
        }
        st[0] = 0;
        wt[G->V] = maxWT;
        for (min = 0; min != G->V; ) {
                v = min;
                st[min] = fr[min];
                for (w = 0, min = G->V; w < G->V; w++) {
                        if (st[w] == -1) {
                                if (P < wt[w]) {
                                        wt[w] = P;
                                        fr[w] = v;
                                }
                                if (wt[w] < wt[min]) {
                                        min = w;
                                }
                        }
                }
        }
}