// 单源最短路径算法
#include "ljjz.h" // 引入邻接矩阵创建程序
typedef enum{FALSE, TRUE} boolean; // FALSE 为 0，TRUE 为 1
typedef int dist[M]; // 距离向量类型
typedef int path[M]; // 路径类型

// Dijkstra 算法求解单源最短路径
void dijkstra(Mgraph g, int v0, path p, dist d)
{
        boolean final[M]; // 表示当前元素是否已求出最短路径
        int i, k, j, v, min, x;
        // 第一步 初始化集合 S 与距离向量 d
        for (v = 0; v < g.n; v++) {
                final[v] = FALSE;
                d[v] = g.edges[v0][v];
                if (d[v]<FINITY && d[v]!=0)
                        p[v] = v0;
                else
                        p[v] = -1; // v 无前驱
        }
        final[v0] = TRUE;
        d[v0] = 0; // 初始时 s 中只有 v0 一个结点
        // 第二步 依次找出 n-1 个结点加入 S 中
        for (i = 1; i < g.n; i++) {
                min = FINITY;
                for (k = 0; k < g.n; ++k) { // 找最小边入结点
                        if (!final[k] && d[k]<min) { // !final[k] 表示 k 还在 V-S中
                                v = k;
                                min = d[k];
                        }
                        // 输出本次入选的顶点距离
                        printf("\n%c---%d\n", g.vexs[v], min);
                        if (min == FINITY)
                                return;
                        final[v] = TRUE; // v 加入 S
                        // 第三步 修改 S 与 V-S 中各结点的距离
                        for (k = 0; k < g.n; ++k) {
                                if (!final[k] && (min+g.edges[v][k]<d[k])) {
                                        d[k] = min + g.edges[v][k];
                                        p[k] = v;
                                }
                        }
                }
        }
}

// 输出有向图的最短路径
void print_gpd(Mgraph g, path p, dist d)
{
        int st[M], i, pre, top = -1; // 定义栈 st 并初始化空栈
        for (i = 0; i < g.n; i++) {
                printf("\n距离向量：%7d，path：", d[i]);
                st[++top] = i;
                pre = p[i];
                while (pre != -1) { // 从第 i 个顶点开始向前搜索最短路径上的顶点
                        st[++top] = pre;
                        pre = p[pre];
                }
                while (top > 0)
                        printf("%2d", st[top--]);
        }
}

int main()
{
        Mgraph g; // 有向图邻接矩阵
        path p; // 路径向量
        dist d; // 最短路径向量
        int v0;
        creat(&g, "g13.txt", 1); // 假设图 8.24 所示的有向网 G[13] 的输入文件为 g13.txt
        printf("输入源点 v0\n");
        scanf("%d", &v0); // 输入源点
        dijkstra(g, v0, p, d); // 求 v[0] 到其他各点的最短距离
        print_gpd(g, p, d); // 输出 v[0] 到其它各点的路径信息及距离
        return 0;
}