// 二项队列中的插入操作

PQlink PQinsert(PQ pq, Item v)
{
        int i;
        PQlink c, t = malloc(sizeof *t);
        c = t;
        c->l = z;
        c->r = z;
        c->key = v;
        for (i = 0; i < maxBQsize; i++) {
                if (c == z) {
                        break;
                }
                if (pq->bq[i] == z) {
                        pq->bq[i] = c;
                        break;
                }
                c = pair(c, pq->bq[i]);
                pq->bq[i] = z;
        }
        return t;
}