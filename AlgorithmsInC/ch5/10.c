// 斐波纳契数（递归实现）

int F(int i)
{
        if (i < 1) {
                return 0;
        }
        if (i == 1) {
                return 1;
        }
        return F(i-1) + F(i-2);
}