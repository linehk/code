// 求两个正整数的最大公约数
int gcd(int m, int n)
{
        int k;
        if (n == 0) {
                return m;
        } else if (n > m) {
                return gcd(n, m);
        } else {
                k = m % n;
                return gcd(n, k);
        }
}