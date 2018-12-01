typedef int Vertex;

struct TableEntry
{
        List Header;
        int Known;
        DistType Dist;
        Vertex Path;
};

#define NotAVertex (-1)
typedef struct TableEntry Table[NumVertex];

void InitTable(Vertex Start, Graph G, Table T)
{
        int i;

        ReadGraph(G, T);
        for (i = 0; i < NumVertex; i++)
        {
                T[i].Known = False;
                T[i].Dist = Infinity;
                T[i].Path = NotAVertex;
        }
        T[Start].Dist = 0;
}

void PrintPath(Vertex V, Table T)
{
        if (T[V].Path != NotAVertex)
        {
                PrintPath(T[V].Path, T);
                printf(" to");
        }
        printf("%v", V);
}

void Dijkstra(Table T)
{
        Vertex V, W;

        for (; ; )
        {
                V = smallest unknown distance vertex;
                if (V == NotAVertex)
                        break;
                
                T[V].Known = True;
                for each W adjacent to V
                {
                        if (!T[W].Known)
                        {
                                if (T[V].Dist + Cvw < T[W].Dist)
                                {
                                        Decrease(T[W].Dist to T[V].Dist + Cvw);
                                        T[W].Path = V;
                                }
                        }
                }
        }
}