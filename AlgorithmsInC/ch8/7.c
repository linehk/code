// 自顶向下表归并排序

link merge(link a, link b);

link mergesort(link c)
{
        link a, b;
        if (c == NULL || c->next == NULL) {
                return c;
        }
        a = c;
        b = c->next;
        while ((b != NULL) && (b->next != NULL)) {
                c = c->next;
                b = b->next->next;
        }
        b = c->next;
        c->next = NULL;
        return merge(mergesort(a), mergesort(b));
}