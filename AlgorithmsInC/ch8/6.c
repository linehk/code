// 链表归并

link merge(link a, link b)
{
        struct node head;
        link c = &head;
        while ((a != NULL) && (b != NULL)) {
                if (less(a->item, b->item)) {
                        c->next = a;
                        c = a;
                        a = a->next;
                } else {
                        c->next = b;
                        c = b;
                        b = b->next;
                }
        }
        c->next = (a == NULL) ? b : a;
        return head.next;
}