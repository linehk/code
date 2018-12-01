// 一个递归程序

int F(int X)
{
        if (X == 0)
                return 0;
        else
                return 2 * F(X - 1) + X * X;
}