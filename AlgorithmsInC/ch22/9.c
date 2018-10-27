// 顶点势的计算

#define ST(i) st[i]->dup->v
static int valid;
static int phi[maxV];

int phiR(link st[], int v)
{
        if (ST(v) == v) {
                mark[v] = valid;
                return -C;
        }
        if (mark[v] != valid) {
                phi[v] = phiR(st, ST(v)) - st[v]->cost;
        }
        mark[v] = valid;
        return phi[v];
}