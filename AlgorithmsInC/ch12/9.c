// 在 BST 上的插入（非递归）操作

void STinsert(Item item)
{
        Key v = key(item);
        link p = head, x = p;
        if (head == NULL) {
                head = NEW(item, NULL, NULL, 1);
                return;
        }
        while (x != NULL) {
                p = x;
                x->N++;
                x = less(v, key(x->item)) ? x->l : x->r;
        }
        x = NEW(item, NULL, NULL, 1);
        if (less(v, key(p->item))) {
                p->l = x;
        } else {
                p->r = x;
        }
}