// 图的深度优先遍历算法
#include "ljb.h"
int visited[M];

// 从顶点 i 开始深度优先遍历图的连通分量
void dfs(LinkedGraph g, int i)
{
        EdgeNode *p;
        printf("访问顶点：%c\n", g.adjlist[i].vertex); // 访问顶点 i
        visited[i] = 1;
        p = g.adjlist[i].FirstEdge;
        while (p) { // 从 p 的邻接点出发进行深度优先搜索
                if (!visited[p->adjvex])
                        dfs(g, p->adjvex);
                p = p->next;
        }
}

// 深度优先遍历图
void DfsTraverse(LinkedGraph g)
{
        int i;
        for (i = 0; i < g.n; i++)
                visited[i] = 0; // 初始化标志数组
        for (i = 0; i < g.n; i++) {
                if (!visited[i]) // v[i] 未访问过
                        dfs(g, i);
        }
}