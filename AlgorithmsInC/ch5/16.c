// 层序遍历

void traverse(link h, void (*visit)(link))
{
        QUEUEinit(max);
        QUEUEput(h);
        while (!QUEUEempty()) {
                (*visit)(h = QUEUEget());
                if (h->l != NULL) {
                        QUEUEput(h->l);
                }
                if (h->r != NULL) {
                        QUEUEput(h->r);
                }
        }
}