// 使用 BST 排序

void sortR(link h, void (*visit)(Item))
{
        if (h == z) {
                return;
        }
        sortR(h->l, visit);
        visit(h->item);
        sortR(h->r, visit);
}

void STsort(void (*visit)(Item))
{
        sortR(head, visit);
}