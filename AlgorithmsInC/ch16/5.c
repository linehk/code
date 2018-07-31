// 可扩展的散列定义和初始化

typedef struct STnode* link;
struct STnode {
        Item b[M];
        int m;
        int k;
};

static link *dir;
static int d, D, N;

link NEW()
{
        link x = malloc(sizeof *x);
        x->m = 0;
        x->k = 0;
        return x;
}

void STinit(int maxN)
{
        d = 0;
        N = 0;
        D = 1;
        dir = malloc(D*(sizeof *dir));
        dir[0] = NEW();
}