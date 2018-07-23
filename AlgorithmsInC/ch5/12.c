// 背包问题（递归实现）

typedef struct {
        int size;
        int val;
} Item;

int knap(int cap)
{
        int i, space, max, t;
        for (i = 0, max = 0; i < N; i++) {
                if ((space = cap-items[i].size) >= 0) {
                        if ((t = knap(space) + items[i].val) > max) {
                                max = t;
                        }
                }
        }
        return max;
}