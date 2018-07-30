// 双重散列

void STinsert(Item item)
{
        Key v = key(item);
        int i = hash(v, M);
        int k = hashtwo(v, M);
        while (!null(i)) {
                i = (i+k) % M;
        }
        st[i] = item;
        N++;
}

Item STsearch(Key v)
{
        int i = hash(v, M);
        int k = hashtwo(v, M);
        while (!null(i)) {
                if eq(v, key(st[i])) {
                        return st[i];
                } else {
                        i = (i+k) % M;
                }
        }
        return NULLitem;
}