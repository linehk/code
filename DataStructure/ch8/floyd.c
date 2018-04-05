// 所有顶点对最短路径算法
#include "ljjz.h" // 引入邻接矩阵创建程序
typedef int dist[M][M]; // 距离向量距离
typedef int path[M][M]; // 路径类型

// Floyd 方法求所有顶点对间的最短路径
void floyd(Mgraph g, path p, dist d)
{
        int i, j, k;
        for (i = 0; i < g.n; i++) { // 初始化
                for (j = 0; j < g.n; j++) {
                        d[i][j] = g.edges[i][j];
                        if (i!=j && d[i][j]<FINITY)
                                p[i][j] = i;
                        else
                                p[i][j] = -1;
                }
        }
        for (k = 0; k < g.n; k++) { // 递推求解每一对顶点间的最短路径
                for (i = 0; i < g.n; i++) {
                        for (j = 0; j < g.n; j++) {
                                if (d[i][j] > d[i][k]+d[k][j]) {
                                        d[i][j] = d[i][k] + d[k][j];
                                        p[i][j] = k;
                                }
                        }
                }
        }
}