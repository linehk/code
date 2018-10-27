// 计算流成本

int GRAPHcost(Graph G)
{
        int i;
        link u;
        int cost = 0;
        for (i = 0; i < G->V; i++) {
                for (u = G->adj[i]; u != NULL; u = u->next) {
                        if ((u->cap > 0) && (u->cost != C)) {
                                cost += (u->flow) * (u->cost);
                        }
                }
        }
        return cost;
}