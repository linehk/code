// 动态散列插入（用于线性探测）

void expand();

void STinsert(Item item)
{
        Key v = key(item);
        int i = hash(v, M);
        while (!null(i)) {
                i = (i+1) % M;
        }
        st[i] = item;
        if (N++ >= M/2) {
                expand();
        }
}

void expand()
{
        int i;
        Item *t = st;
        init(M+M);
        for (i = 0; i < M/2; i++) {
                if (key(t[i]) != key(NULLitem)) {
                        STinsert(t[i]);
                }
        }
        free(t);
}