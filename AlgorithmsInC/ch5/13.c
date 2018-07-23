// 背包问题（动态规划）

int knap(int M)
{
        int i, space, max, maxi, t;
        if (maxKnown[M] != unknown) {
                return maxKnown[M];
        }
        for (i = 0, max = 0; i < N; i++) {
                if ((space = M-item[i].size) >= 0) {
                        if ((t = knap(space) + items[i].val) > max) {
                                max = t;
                                maxi = i;
                        }
                }
        }
        maxKnown[M] = max;
        itemKnown[M] = items[maxi];
        return max;
}