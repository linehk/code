// 预流-推进最大流实现

static int h[maxV];
static int wt[maxV];
#define P (Q > wt[v] ? wt[v] : Q)
#define Q (u->cap < 0 ? -u->flow : u->cap - u->flow)

int GRAPHmaxflow(Graph G, int s, int t)
{
        int v;
        int w;
        int x;
        link u;
        GQinit();
        for (v = 0; v < G->V; v++) {
                wt[v] = 0;
        }
        GQput(s);
        wt[s] = maxWT;
        wt[t] = -maxWT;
        while (!GQempty()) {
                v = GQget();
                for (u = G->adj[v]; u != NULL; u = u->next) {
                        if (P > 0 && v == s || h[v] == h[u->v] + 1) {
                                w = u->v;
                                x = P;
                                u->flow += x;
                                u->dup->flow -= x;
                                wt[v] -= x;
                                wt[w] += x;
                                if ((w != s) && (w != t)) {
                                        GQput(w);
                                }
                        }
                }
                if ((v != s) && (v != t)) {
                        if (wt[v] > 0) {
                                h[v]++;
                                GQput(v);
                        }
                }
        }
}