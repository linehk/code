#include "radisort.h"
#include "distribu.c"
#include "collect.c"

// 静态链式基数排序算法
// 采用静态链表表示的顺序表。最 r 进行基数排序，使得 r 成为按关键字自小到大
// 的有序静态链表，r[0] 为头结点
void radixsort(list *r)
{
        int i;
        for (i = 0; i < N; i++)
                r[i]->link = i + 1;
        r[N]->link = 0; // 建立初始静态链表
        for (i = B; i >= 1; i--) { // 按最低位优先依次对各关键字进行分配和收集
                distribute(r, i); // 第 i 趟分配
                collect(r); // 第 i 趟收集
        }
}