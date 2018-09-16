// 简单
void Topsort(Graph G)
{
        int Counter;
        Vertex V, W;

        for (Counter = 0; Counter < NumVertex; Counter++)
        {
                V = FindNewVertexOfIndegreeZero();
                if (V == NotAVertex)
                {
                        Error("Graph has a cycle");
                        break;
                }
                TopNum[V] = Counter;
                for each W adjacent to V
                        Indegree[W]--;
        }
}

//
void Topsort(Graph G)
{
        Queue Q;
        int Counter = 0;
        Vertex V, W;

        Q = CreateQueue(NumVertex);
        MakeEmpty(Q);
        for each vertex V
        {
                if (Indegree[V] == 0)
                        Enqueue(V, Q);
        }

        while (!IsEmpty(Q))
        {
                V = Dequeue(Q);
                TopNum[V] = ++Counter;

                for each W adjacent to V
                {
                        if (--Indegree[W] == 0)
                                Enqueue(W, Q);
                }
        }

        if (Counter != NumVertex)
        {
                Error("Graph has cycle");
        }

        DisposeQueue(Q);
}