// 跳跃表的删除

void deleteR(link t, Key v, int k)
{
        link x = t->next[k];
        if (!less(key(x->item), v)) {
                if (eq(v, key(x->item))) {
                        t->next[k] = x->next[k];
                }
                if (k == 0) {
                        free(x);
                        return;
                }
                deleteR(t, v, k-1);
                return;
        }
        deleteR(t->next[k], v, k);
}

void STdelete(Key v)
{
        deleteR(head, v, lgN);
        N--;
}