// 连接两个大小相等的二次幂堆

PQlink pair(PQlink p, PQlink q)
{
        if (less(p->key, q->key)) {
                p->r = q->l;
                q->l = p;
                return q;
        } else {
                q->r = p->l;
                p->l = q;
                return p;
        }
}