// B 树节点分裂

link split(link h)
{
        int j;
        link t = NEW();
        for (j = 0; j < M/2; j++) {
                t->b[j] = h->b[M/2+j];
        }
        h->m = M/2;
        t->m = M/2;
        return t;
}