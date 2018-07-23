// 汉诺塔的解

void hanoi(int N, int d)
{
        if (N == 0) {
                return;
        }
        hanoi(N-1, -d);
        shift(N, d);
        hanoi(N-1, -d);
}