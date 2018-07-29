// 跳跃表中的搜索

Item searchR(link t, Key v, int k)
{
        if (t == z) {
                return NULLitem;
        }
        if (eq(v, key(t->item))) {
                return t->item;
        }
        if (less(v, key(t->next[k]->item))) {
                if (k == 0) {
                        return NULLitem;
                }
                return searchR(t, v, k-1);
        }
        return searchR(t->next[k], v, k);
}

Item STsearch(Key v)
{
        return searchR(head, v, lgN);
}