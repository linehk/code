// 邻接矩阵类型定义
#include <stdio.h>
#define FINITY 5000 // 此处用 5000 代表无穷大
#define M 20 // 最大顶点数
typedef char vertextype; // 顶点值类型
typedef int edgetype; // 权值类型
typedef struct {
        vertextype vexs[M]; // 顶点信息域
        edgetype edges[M][M]; // 邻接矩阵
        int n, e; // 图中顶点总数与边数
} Mgraph;

// 建立图的邻接矩阵存储结构
void creat(Mgraph *g, char *s, int c)
{
        int i, j, k, w; // c=0 表示建立无向图，否则表示建立有向图
        FILE *rf;
        rf = fopen(s, "r"); // 从文件中读取图的边信息
        if (rf) {
                fscanf(rf, "%d%d", &g->n, &g->e); // 读入图的顶点数与边数
                for (i = 0; i < g->n; i++) // 读入图的顶点值
                        fscanf(rf, "%1s", &g->vexs[i]);
                for (i = 0; i < g->n; i++) { // 初始化邻接矩阵
                        for (j = 0; j < g->n; j++) {
                                if (i == j)
                                        g->edges[i][j] = 0;
                                else
                                        g->edges[i][j] = FINITY;
                        }
                }
                for (k = 0; k < g->e; k++) { // 读入网络中的边
                        fscanf(rf, "%d%d%d", &i, &j, &w);
                        g->edges[i][j] = w;
                        if (c == 0)
                                g->edges[j][i] = w; // 建立无向图邻接矩阵
                }
                fclose(rf); // 关闭文件
        } else {
                g->n = 0;
        }
}