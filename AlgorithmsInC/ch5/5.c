// 链表递归函数示例

int count(link x)
{
        if (x == NULL) {
                return 0;
        }
        return 1 + count(x->next);
}

void traverse(link h, void (*visit)(link))
{
        if (h == NULL) {
                return;
        }
        (*visit)(h);
        traverse(h->next, visit);
}

void traverseR(link h, void (*visit)(link))
{
        if (h == NULL) {
                return;
        }
        traverseR(h->next, visit);
        (*visit)(h);
}

link delete(link x, Item v)
{
        if (x == NULL) {
                return NULL;
        }
        if (eq(x->item, v)) {
                link t = x->next;
                free(x);
                return t;
        }
        x->next = delete(x->next, v);
        return x;
}