// 菲波纳契递归

long int Fib(int N)
{
        if (N <= 1)
                return 1;
        else
                return Fib(N - 1) + Fib(N - 2);
}