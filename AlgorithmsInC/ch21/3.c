// 计算网的路径

void GRAPHdiameter(Graph G)
{
        int v;
        int w;
        int vMAX = 0;
        int wMAX = 0;
        double MAX = 0.0;
        GRAPHspALL(G);
        for (v = 0; v < G->V; v++) {
                for (w = 0; w < G->V; w++) {
                        if (GRAPHspPATH(G, v, w) != G->V) {
                                if (MAX < GRAPHspDIST(G, v, w)) {
                                        vMAX = v;
                                        wMAX = w;
                                        MAX = GRAPHspDIST(G, v, w);
                                }
                        }
                }
        }
        printf("Diameter is %f\n", MAX);
        for (v = vMAX; v != wMAX; v = w) {
                printf("%d-", v);
                w = GRAPHspPATH(G, v, wMAX);
        }
        printf("%d\n", w);
}