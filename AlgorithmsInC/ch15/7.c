// 存在线索的搜索和插入

typedef struct STnode *link;
struct STnode {
        link next[R];
};
static link head;

void STinit()
{
        head = NULL;
}

link NEW()
{
        int i;
        link x = malloc(sizeof *x);
        for (i = 0; i < R; i++) {
                x->next[i] = NULL;
        }
        return x;
}

Item searchR(link h, Key v, int w)
{
        int i = digit(v, w);
        if (h == NULL) {
                return NULLitem;
        }
        if (i == NULLdigit) {
                return v;
        }
        return searchR(h->next[i], v, w+1);
}

Item STsearch(Key v)
{
        return searchR(head, v, 0);
}

link insertR(link h, Item item, int w)
{
        Key v = key(item);
        int i = digit(v, w);
        if (h == NULL) {
                h = NEW();
        }
        if (i == NULLdigit) {
                return h;
        }
        h->next[i] = insertR(h->next[i], v, w+1);
        return h;
}

void STinsert(Item item)
{
        head = insertR(head, item, 0);
}