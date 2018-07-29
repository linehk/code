// 跳跃表的插入

int randX()
{
        int i, j, t = rand();
        for (i = 1, j = 2; i < lgNmax; i++, j += j) {
                if (t > RAND_MAX/j) {
                        break;
                }
        }
        if (i > lgN) {
                lgN = i;
        }
        return i;
}

void insertR(link t, link x, int k)
{
        Key v = key(x->item);
        if (less(v, key(t->next[k]->item))) {
                if (k < x->sz) {
                        x->next[k] = t->next[k];
                        t->next[k] = x;
                }
                if (k == 0) {
                        return;
                }
                insertR(t, x, k-1);
                return;
        }
        insertR(t->next[k], x, k);
}

void STinsert(Item item)
{
        insertR(head, NEW(item, randX()), lgN);
        N++;
}