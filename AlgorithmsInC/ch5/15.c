// 前序遍历（非递归）

void traverse(link h, void (*visit)(link))
{
        STACKinit(max);
        STACKpush(h);
        while (!STACKempty()) {
                (*visit)(h = STACKpop());
                if (h->r != NULL) {
                        STACKpush(h->r);
                }
                if (h->l != NULL) {
                        STACKpush(h->l);
                }
        }
}