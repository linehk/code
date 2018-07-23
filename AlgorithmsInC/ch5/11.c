// 斐波纳契数（动态规划）

int F(int i)
{
        int t;
        if (knownF[i] != unknown) {
                return knownF[i];
        }
        if (i == 0) {
                t = 0;
        }
        if (i == 1) {
                t = 1;
        }
        if (i > 1) {
                t = F(t-1) + F(t-2);
        }
        return knownF[i] = t;
}