#include <stdio.h>
// 拓扑排序算法
#define M 20
typedef char vertextype;
typedef struct node { // 边结点类型定义
        int adjvex;
        struct node *next;
} edgenode;
typedef struct de { // 带顶点入度的头结点定义
        edgenode *FirstEdge;
        vertextype vertex;
        int id; // 顶点的入度域
} vertexnode;
typedef struct { // AOV 网络的邻接表结构
        vertexnode adjlist[M];
        int n, e;
} AovGraph;

// 拓扑排序
int TopSort(AovGraph g)
{
        int k = 0, i, j, v, flag[M];
        int queue[M]; // 队列
        int front, rear;
        edgenode *p;
        front = rear = 0; // 初始化空队列
        for (i = 0; i < g.n; i++)
                flag[i] = 0; // 访问标记初始化
        for (i = 0; i < g.n; i++) { // 先将所有入度为 0 的结点入队
                if (g.adjlist[i].id==0 && flag[i]==0) {
                        queue[rear++] = i;
                        flag[i] = 1;
                }
        }
        printf("\nAOV 网的拓扑序列是：\n");
        while (front < rear) { // 当队列不为空
                v = queue[front++]; // 队首元出队
                printf("%c ", g.adjlist[v].vertex);
                k++; // 计数器加 1
                p = g.adjlist[v].FirstEdge;
                while (p) { // 将所有与 v 邻接的顶点的入度减 1
                        j = p->adjvex;
                         // 若入度为 0 则将进队
                        if (--g.adjlist[j].id==0 && flag[j]==0) {
                                queue[rear++] = j;
                                flag[j] = 1;
                        }
                        p = p->next;
                }
        }
        return k;
}