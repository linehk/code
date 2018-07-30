// 在线性探测散列表中实现删除

void STdelete(Item item)
{
        int j, i = hash(key(item), M);
        Item v;
        while (!null(i)) {
                if eq(key(item), key(st[i])) {
                        break;
                } else {
                        i = (i+1) % M;
                }
        }
        if (null(i)) {
                return;
        }
        st[i] = NULLitem;
        N--;
        for (j = i+1; !null(j); j = (j+1) % M, N--) {
                v = st[j];
                st[j] = NULLitem;
                STinsert(v);
        }
}