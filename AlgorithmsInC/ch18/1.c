// 深度优先搜索（邻接矩阵）

#define dfsR search
void dfsR(Graph G, Edge e)
{
        int t;
        int w = e.w;
        pre[w] = cnt++;
        for (t = 0; t < G->V; t++) {
                if (G->adj[w][t] != 0) {
                        if (pre[w] == -1) {
                                dfsR(G, EDGE(w, t));
                        }
                }
        }
}