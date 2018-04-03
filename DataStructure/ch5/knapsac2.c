#include <stdio.h>

#define MAXSIZE 50
#define MAXS 25
int w[MAXSIZE]; // 按照从大到小的顺序存放各物品的重量值

// 简单背包问题的非递归算法实现
// 在 w[1], w[2], ..., w[m] 中选出若干件物品，使其重量和为 s
void knapsack2(int s, int m)
{
        typedef struct {
                int ss; // 存储被选中物体的重量
                int mm; // 存储被选中物体的编号
        } stacklem;
        stacklem stack[MAXS]; // 用于记录回溯点的栈
        int i, t, top, nofail; // top 为栈顶指针，nofail 为求解成功的标志
        t = 0; // 变量 t 用于记录已被选的物体重量总和
        top = 0;
        nofail = 1;
        while (s!=t && nofail) { // 如尚未找到解且当前无法判断求解失败
                if (s>=t+w[1] && m>0) { // 表示存在至少还有一个物体被选的可能
                        stack[top].ss = w[m]; // 选择 w[m] 并将它进栈
                        stack[top].mm = m;
                        top++;
                        t = t + w[m];
                        --m;
                } else { // 表示刚才一个选择不适合，需进行回溯
                        if (m == 0) {
                                --top;
                                t = t - stack[top].ss;
                        }
                        if (top < 1) { // 栈已为空，求解失败
                                nofail = 0;
                        } else { // 表示栈顶元素被选不适合，从其前一个元素开始重新试探
                                --top;
                                m = stack[top].mm - 1;
                                t = t - stack[top].ss;
                        }
                }
        }
        if (s == t) { // 求解成功，将解输出
                for (i = 0; i < top; ++i)
                        printf("\n%d\n", stack[i].ss);
        } else {
                printf("这里没有任何选择！\n"); // 求解失败
        }
}