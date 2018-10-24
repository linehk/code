// 广度优先搜索（邻接矩阵）

#define bfs search
void bfs(Graph G, Edge e)
{
        int v;
        int w;
        QUEUEput(e);
        while (!QUEUEempty()) {
                if (pre[(e = QUEUEget()).w] == -1) {
                        pre[e.w] = cnt++;
                        st[e.w] = e.v;
                        for (v = 0; v < G->V; v++) {
                                if (G->adj[e.w][v] == 1) {
                                        if (pre[v] == -1) {
                                                QUEUEput(EDGE(e.w, v));
                                        }
                                }
                        }
                }
        }
}