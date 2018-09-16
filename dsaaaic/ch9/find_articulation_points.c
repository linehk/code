void AssignNum(Vertex V)
{
        Vertex W;

        Num[V] = Counter++;
        Visited[V] = True;
        for each W adjacent to V
                if (!Visited[W])
                {
                        Parent[W] = V;
                        AssignNum(W);
                }
}

void AssignLow(Vertex V)
{
        Vertex W;

        Low[V] = Num[V];
        for each W adjacent to V
        {
                if (Num[W] > Num[V])
                {
                        AssignLow(W);
                        if (Low[W] >= Num[V])
                                printf("%v is an articulation point\n", v);
                        Low[V] = Min(Low[V], Low[W]);
                }
                else if (Parent[V] != W)
                        Low[V] = Min(Low[V], Num[W]);
        }
}

void FindArt(Vertex V)
{
        Vertex W;

        Visited[V] = True;
        Low[V] = Num[V] = Counter++;
        for each W adjacent to V
        {
                if (!Visited[W])
                {
                        Parent[W] = V;
                        FindArt(W);
                        if (Low[W] >= Num[V])
                                printf("%v is an articulation point\n");
                        Low[V] = Min(Low[V], Low[W]);
                }
                else if (Parent[V] != W)
                        Low[V] = Min(Low[V], Num[W]);
        }
}