// B 树的定义及初始化

typedef struct STnode* link;
typedef struct {
        Key key;
        union {
                link next;
                Item item;
        } ref;
} entry;

struct STnode {
        entry b[M];
        int m;
};

static link head;
static int H, N;

link NEW()
{
        link x = malloc(sizeof *x);
        x->m = 0;
        return x;
}

void STinit(int maxN)
{
        head = NEW();
        H = 0;
        N = 0;
}