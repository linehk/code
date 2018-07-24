// 自底向上表归并排序

link mergesort(link t)
{
        link u;
        for (QUEUEinit(); t != NULL; t = u) {
                u = t->next;
                t->next = NULL;
                QUEUEput(t);
        }
        t = QUEUEget();
        while (!QUEUEempty()) {
                QUEUEput(t);
                t = merge(QUEUEget(), QUEUEget());
        }
        return t;
}