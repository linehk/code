#include "ljb.h"
int visited[M]; // 全局标志变量

// 从顶点 i 出发广度优先遍历图 g 的连通分量
void bfs(LinkedGraph g, int i)
{
        int j;
        EdgeNode *p;
        int queue[M], front, rear; // FIFO 队列
        front = rear = 0; // 初始化空队列
        printf("%c ", g.adjlist[i].vertex); // 访问源点 v
        visited[i] = 1;
        queue[rear++] = i; // 被访问结点进队
        while (rear > front) { // 当队列非空时，执行下列循环体
                j = queue[front++]; // 出队
                p = g.adjlist[j].FirstEdge;
                while (p) {
                        if (visited[p->adjvex] == 0) {
                                printf("%c ", g.adjlist[p->adjvex].vertex);
                                queue[rear++] = p->adjvex;
                                visited[p->adjvex] = 1;
                        }
                        p = p->next;
                }
        }
}

// 广度优先遍历图 g
int BfsTraverse(LinkedGraph g)
{
        int i, count = 0;
        for (i = 0; i < g.n; i++)
                visited[i] = 0; // 初始化标志数组
        for (i = 0; i < g.n; i++) {
                if (!visited[i]) { // v[i] 未被访问过
                        printf("\n");
                        count++; // 连通分量个数加 1
                        bfs(g, i);
                }
        }
        return count;
}

int main()
{
        LinkedGraph g;
        int count;
        creat(&g, "g11.txt", 0); // 加速 G[11] 的图信息存储在 g11.txt 文件中
        printf("\n图为：\n"); // 输出图的邻接表
        print(g);
        count = BfsTraverse(g); // 从顶点 0 出发广度优先遍历图
        printf("\n该图共有 %d 个连通分量。\n", count);
        return 0;
}