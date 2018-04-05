// Prim 求解最小生成树算法
#include "ljjz.h"
typedef struct edgedata { // 用于保存最小生成树的边类型定义
        int beg, en; // beg en 是边顶点序号
        int length; // 边长
} edge;

// prim 算法构造最小生成树
void prim(Mgraph g, edge tree[M-1])
{
        edge x;
        int d, min, j, k, s, v;
        for (v = 1; v <= g.n-1; v++) { // 建立初始入选点，并初始化生成树边集 tree
                tree[v-1].beg = 0; // 此处从 v[0] 开始求最小生成树
                tree[v-1].en = v;
                tree[v-1].length = g.edges[0][v];
        }
        for (k = 0; k <= g.n-3; k++) { // 依次求当前 (第 k 条) 最小两栖边，并加入 tree
                min = tree[k].length;
                s = k;
                for (j = k+1; j <= g.n-2; j++) {
                        if (tree[j].length < min) {
                                min = tree[j].length;
                                s = j;
                        }
                }
                v = tree[s].en; // 入选顶点为 v
                x = tree[s];
                tree[s] = tree[k];
                tree[k] = x; // 通过交换，将当前最小边加入到 tree 中
                 // 由于新顶点 v 的加入，修改两栖边的基本信息
                for (j = k+1; j <-g.n-2; j++) {
                        d = g.edges[v][tree[j].en];
                        if (d < tree[j].length) {
                                tree[j].length = d;
                                tree[j].beg = v;
                        }
                }
        }
        printf("\n最小生成树为：\n"); // 输出最小生成树
        for (j = 0; j <= g.n-2; j++) {
                printf("\n%c---%c %d\n", g.vexs[tree[j].beg], g.vexs[tree[j].en], 
                        tree[j].length);
        }
        printf("\n根结点为：%c\n", g.vexs[0]);
}

int main()
{
        Mgraph g;
        edge tree[M-1]; // 用于存放最小生成树的 M-1 条边
        char filename[20];
        printf("输入图信息文件名：\n"); // 输入图信息的文件名
        gets(filename);
        creat(&g, filename, 0); // 创建无向图的邻接矩阵
        prim(g, tree); // 求解图的最小生成树
        return 0;
}