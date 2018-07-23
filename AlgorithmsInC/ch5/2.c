// 有问题的递归程序

int puzzle(int N)
{
        if (N == 1) {
                return 1;
        }
        if (N%2 == 0) {
                return puzzle(N/2);
        } else {
                return puzzle(3*N+1);
        }
}