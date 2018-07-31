// 可扩展散列法的搜索

Item search(link h, Key v)
{
        int j;
        for (j = 0; j < h->m; j++) {
                if (eq(v, key(h->b[j]))) {
                        return h->b[j];
                }
        }
        return NULLitem;
}

Item STsearch(Key v)
{
        return search(dir[bits(v, 0, d)], v);
}