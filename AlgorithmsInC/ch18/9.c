// 改进 BFS

void bfs(Graph G, Edge e)
{
        int v;
        int w;
        QUEUEput(e);
        pre[e.w] = cnt++;
        while (!QUEUEempty()) {
                e = QUEUEget();
                w = e.w;
                st[w] = e.v;
                for (v = 0; v < G->V; v++) {
                        if ((G->adj[w][v] == 1) && (pre[v] == -1)) {
                                QUEUEput(EDGE(w, v));
                                pre[v] = cnt++;
                        }
                }
        }
}