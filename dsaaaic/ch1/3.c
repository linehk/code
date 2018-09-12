// 打印整数的递归例程

#define PrintDigit(Ch) (putchar((Ch) + '0'))

void PrintOut(unsigned int N)
{
        if (N >= 10)
                PrintOut(N / 10);
        PrintDigit(N % 10);
}