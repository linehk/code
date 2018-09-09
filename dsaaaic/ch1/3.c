// 打印整数的递归例程

void
PrintOut(unsigned int N)
{
        if (N >= 10)
                PrintOut(N / 10);
        PrintDigit(N % 10);
}