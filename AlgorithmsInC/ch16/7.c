// 可扩展散列法的插入

link split(link h)
{
        int j;
        link t = NEW();
        while (h->m == 0 || h->m == M) {
                h->m = 0;
                t->m = 0;
                for (j = 0; j < M; j++) {
                        if (bits(h->b[j], h->k, 1) == 0) {
                                h->b[(h->m)++] = h->b[j];
                        } else {
                                t->b[(t->m)++] = h->b[j];
                        }
                }
                t->k = ++(h->k);
        }
        insertDIR(t, t->k);
}

void insert(link h, Item item)
{
        int i, j;
        Key v = key(item);
        for (j = 0; j < h->m; j++) {
                if (less(v, key(h->b[j]))) {
                        break;
                }
        }
        for (i = (h->m)++; i > j; j--) {
                h->b[i] = h->b[i-1];
        }
        h->b[j] = item;
        if (h->m == M) {
                split(h);
        }
}

void STinsert(Item item)
{
        insert(dir[bits(key(item), 0, d)], item);
}