#include <stdio.h>

// 关键路径求解算法
#define M 20
typedef char vertextype;
typedef struct node { // 边结点类型定义
        int adjvex;
        int len; // 边的权值
        struct node *next;
} EdgeNode;
typedef struct de { // 带顶点入度的头结点定义
        EdgeNode *FirstEdge;
        vertextype vertex;
        int id; // 顶点的入度域
} vertexnode;
typedef struct { // AOE 网络的邻接表结构
        vertexnode adjlist[M];
        int n, e;
} AoeGraph;

// 求 AOE 网各事件的最早发生时间
int EarlistTime(AoeGraph gout, int ve[], int seq[])
{
        int count = 0, i, j, v, flag[M];
        int queue[M]; // 队列
        int front = 0, rear = 0;
        EdgeNode *p;
        for (i = 0; i < gout.n; i++) // 初始化每个顶点的最早开始时间 ve[i] 为 0
                ve[i] = 0;
        for (i = 0; i < gout.n; i++)
                flag[i] = 0; // 访问标记初始化
        for (i = 0; i < gout.n; i++) { // 先将所有入度为 0 的结点入队
                if (gout.adjlist[i].id==0 && flag[i]==0) {
                        queue[rear++] = i;
                        flag[i] = 1;
                }
        }
        while (front < rear) { // 当队列不为空时
                v = queue[front++]; // 队首元出队
                printf("%c----->", gout.adjlist[v].vertex);
                seq[count] = v; // 记录拓扑排序当前元素
                count++; // 计数器加 1
                p = gout.adjlist[v].FirstEdge;
                while (p) { // 将所有与 v 邻接的顶点的入度减 1
                        j = p->adjvex;
                        // 若入度为 0 则将进队
                        if (--gout.adjlist[j].id==0 && flag[j]==0) {
                                queue[rear++] = j;
                                flag[j] = 1;
                        }
                        if (ve[v]+p->len > ve[j])
                        // ve[j] 的值是从源点到顶点 j 的最长距离
                                ve[j] = ve[v] + p->len;
                        p = p->next;
                }
        }
        return count;
}

// 求 AOE 网各事件的最晚允许开始时间
void LateTime(AoeGraph gin, int ve[], int vl[], int seq[])
{
        int k = gin.n - 1, i, j, v;
        EdgeNode *p;
        // 初始化 AOE 网中每个顶点的最晚允许开始时间为关键路径长度 
        for (i = 0; i < gin.n; i++)
                vl[i] = ve[seq[gin.n-1]];
        while (k > -1) { // 按照拓扑逆序求各事件的最晚允许开始时间
                v = seq[k];
                p = gin.adjlist[v].FirstEdge;
                while (p) {
                        j = p->adjvex;
                        if (vl[v]-p->len < vl[j])
                                vl[j] = vl[v] - p->len;
                        p = p->next;
                }
                k--;
        }
}