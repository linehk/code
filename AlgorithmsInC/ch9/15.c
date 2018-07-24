// 二项队列中删除最大元素的操作

Item PQdelmax(PQ pq)
{
        int i, max;
        PQlink x;
        Item v;
        PQlink temp[maxBQsize];
        for (i = 0, max = -1; i < maxBQsize; i++) {
                if (pq->bq[i] != z) {
                        if ((max == -1) || less(v, pq->bq[i]->key)) {
                                max = i;
                                v = pq->bq[max]->key;
                        }
                }
        }
        x = pq->bq[max]->l;
        for (i = max; i < maxBQsize; i++) {
                temp[i] = z;
        }
        for (i = max; i > 0; i--) {
                temp[i-1] = x;
                x = x->r;
                temp[i-1]->r = z;
        }
        free(pq->bq[max]);
        pq->bq[max] = z;
        BQjoin(pq->bq, temp);
        return v;
}