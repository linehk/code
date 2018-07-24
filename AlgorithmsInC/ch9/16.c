// 两个二项队列中的连接（合并）操作

#define test(C, B, A) 4*(C) + 2*(B) + 1*(A)

void BQjoin(PQlink *a, PQlink *b)
{
        int i;
        PQlink c = z;
        for (i = 0; i < maxBQsize; i++) {
                switch(test(c != z, b[i] != z, a[i] != z)) {
                case 2:
                        a[i] = b[i];
                        break;
                case 3:
                        c = pair(a[i], b[i]);
                        a[i] = z;
                        break;
                case 4:
                        a[i] = c;
                        c = z;
                        break;
                case 5:
                        c = pair(c, a[i]);
                        a[i] = z;
                        break;
                case 6:
                case 7:
                        c = pair(c, b[i]);
                        break;
                }
        }
}

void PQjoin(PQ a, PQ b)
{
        BQjoin(a->bq, b->bq);
}