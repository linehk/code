// 帕氏线索排序

void sortR(link h, void (*visit)(Item), int w)
{
        if (h->bit <= w) {
                visit(h->item);
                return;
        }
        sortR(h->l, visit, h->bit);
        sortR(h->r, visit, h->bit);
}

void STsort(void (*visit)(Item))
{
        sortR(head->l, visit, -1);
}