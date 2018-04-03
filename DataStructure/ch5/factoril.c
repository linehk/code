// 求正整数 n 的阶乘值
int Fact(int n)
{
        int m;
        if (n == 0) {
                return 1;
        } else {
                m = n * Fact(n-1);
                return m;
        }
}