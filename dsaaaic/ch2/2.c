// 阶乘函数

long int Factorial(int N)
{
        if (N <= 1)
                return 1;
        else
                return N * Factorial(N - 1);
}