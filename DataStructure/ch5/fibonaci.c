// 求第 n 项 Fibonacci 级数值
int Fibona(int n)
{
        int m;
        if (n == 1) {
                return 1;
        } else if (n == 2) {
                return 1;
        } else {
                m = Fibona(n-1) + Fibona(n-1);
                return m;
        }
}