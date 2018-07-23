// 递归树遍历

void traverse(link h, void (*visit)(link))
{
        if (h == NULL) {
                return;
        }
        (*visit)(h);
        traverse(h->l, visit);
        traverse(h->r, visit);
}