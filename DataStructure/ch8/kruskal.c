// kruskal 求解最小生成树算法
#include "ljjz.h"
typedef struct edgedata { // 用于保存最小生成树的边类型定义
        int beg, en; // beg en 是边顶点序号
        int length; // 边的权值长
} edge;

// 对边向量进行快速排序
void QuickSort(edge edges[], int left, int right)
{
        edge x;
        int i, j, flag = 1;
        if (left < right) {
                i = left;
                j = right;
                x = edges[i];
                while (i < j) {
                        while (i<j && x.length<edges[j].length)
                                j--;
                        if (i < j)
                                edges[i++] = edges[j];
                        while (i<j && x.length>edges[i].length)
                                i++;
                        if (i < j)
                                edges[j--] = edges[i];
                }
                edges[i] = x;
                QuickSort(edges, left, i-1);
                QuickSort(edges, i+1, right);
        }
}

// 从图 g 的邻接矩阵读取图的所有边信息
void GetEdge(Mgraph g, edge edges[])
{
        int i, j, k = 0;
        for (i = 0; i < g.n; i++) {
                for (j = 0; j < i; j++) {
                        if (g.edges[i][j]!=0 && g.edges[i][j]<FINITY) {
                                edges[k].beg = i;
                                edges[k].en = j;
                                edges[k++].length = g.edges[i][j];
                        }
                }
        }
}

// kruskal 求解最小生成树算法
void kruskal(Mgraph g)
{
        int i, j, k = 0, ltfl;
        int cnvx[M];
        edge edges[M*M]; // 用于存放图的所有边
        edge tree[M]; // 用于存放最小生成树的边信息
        GetEdge(g, edges); // 读取所有的边
        QuickSort(edges, 0, g.e-1); // 对边进行升序排列
        for (i = 0; i < g.n; i++)
                cnvx[i] = i; // 设置每一个顶点的连通分量
        for (i = 0; i < g.n-1; i++) { // 树中共有 g.n-1 条边
                while (cnvx[edges[k].beg] == cnvx[edges[k].en])
                        k++; // 找到属于两个连通分量权最小的边
                tree[i] = edges[k]; // 将边 k 加入到生成树中
                ltfl = cnvx[edges[k].en]; // 记录选中边的终点的连通分量编号
                for (j = 0; j < g.n; j++) { // 两个连通分量合并为一个连通分量
                        if (cnvx[j] == ltfl)
                                cnvx[j] = cnvx[edges[k].beg];
                }
                k++;
        }
        printf("最小生成树是：\n");
        for (j = 0; j < g.n-1; j++) {
                printf("%c---%c%6d\n", g.vexs[tree[j].beg], g.vexs[tree[j].en],
                        tree[j].length);
        }
}

int main()
{
        Mgraph g;
        char filename[20];
        printf("输入图的文件名：\n");
        gets(filename); // 读入图的输入文件名
        creat(&g, filename, 0); // 创建图的邻接矩阵
        kruskal(g); // Kruskal 算法求解最小生成树
        return 0;
}