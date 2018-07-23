// 阶乘函数（递归实现）

int factorial(int N)
{
        if (N == 0) {
                return 1;
        }
        return N * factorial(N-1);
}

// for (t = 1, i = 1; i <= N; i++) {
//         t *= i;
// }