void WeightedNegative(Table T)
{
        Queue Q;
        Vertex V, W;

        Q = CreateQueue(NumVertex);
        MakeEmpty(Q);
        Enqueue(S, Q);

        while (!IsEmpty(Q))
        {
                V = Dequeue(Q);
                for each W adjacent to V
                        if (T[V].Dist + Cvw < T[W].Dist)
                        {
                                T[W].Dist = T[V].Dist + Cvw;
                                T[W].Path = V;
                                if (W is not already in Q)
                                        Enqueue(W, Q);
                        }
        }
        DisposeQueue(Q);
}