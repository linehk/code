#include <stdio.h>

#define MAXSIZE 50
int w[MAXSIZE]; // 按照从大到小的顺序存放各物品的重量值

// 简单背包问题的递归算法实现
// 在 w[1], w[2], ..., w[m] 中选出若干件物品，使其重量和为 s。若解存在返回 1，否则返回 0
int knapsack1(int s, int m)
{
        int s1, b;
        if (s == 0) { // 寻找问题的解成功
                return 1;
        } else if (s<w[1] || m==0) { // 寻找问题的解不成功
                return 0;
        } else {
                do {
                        s1 = w[m];
                        m--; // 考虑 w[m] 被选择的可能性
                        b = knapsack1(s-s1, m);
                } while (m!=0 && !b);
                if (!b) {
                        return 0;
                } else { // 选择 w[m] 成功，并将其打印输出
                        printf("\n%d", s1);
                        return 1;
                }
        }
}