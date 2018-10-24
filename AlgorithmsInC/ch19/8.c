// 基于源点队列的拓扑排序

#include "QUEUE.h"
static int in[maxN];
void DAGts(Dag D, int ts[])
{
        int i;
        int v;
        link t;
        for (v = 0; v < D->V; v++) {
                in[v] = 0;
                ts[v] = -1;
        }
        for (v = 0; v < D->V; v++) {
                for (t = D->adj[v]; t != NULL; t = t->next) {
                        in[t->v]++;
                }
        }
        QUEUEinit(D->V);
        for (v = 0; v < D->V; v++) {
                if (in[v] == 0) {
                        QUEUEput(v);
                }
        }
        for (i = 0; !QUEUEempty(); i++) {
                ts[i] = (v = QUEUEget());
                for (t = D->adj[v]; t != NULL; t = t->next) {
                        if (--in[t->v] == 0) {
                                QUEUEput(t->v);
                        }
                }
        }
}