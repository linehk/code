#include "radisort.h"

// 静态链式基数排序分配算法
void distribute(list *r, int i)
{
        int j, p;
        for (j = 0; j <= 9; j++) {
                f[j] = 0;
                e[j] = 0; // 各子表初始化为空表
        }
        p = r[0]->link;
        while (p != 0) {
                j = r[p]->key[i]; // j 为 第 i 个排序码
                if (!(f[j]))
                        f[j] = p;
                else
                        r[e[j]]->link = p;
                e[j] = p; // 将 p 所指的结点分配插入第 j 个字表中
                p = r[p]->link; // 继续指向下一个结点进行
        }
}