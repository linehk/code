#include "radisort.h"

// 静态链式基数排序收集算法
// 本算法以 key[i] 从小到大所指各非空子表 (f[j]!=0) 依次链接成
// 一个链表，r[0]->link 指向该链表表头
void collect(list *r)
{
        int j = 0, t;
        while (!f[j])
                j++; // 找第一个非空子表
        r[0]->link = f[j]; // p 指向第一个非空子表中第一个结点
        t = e[j];
        while (j < 9) {
                j++;
                while (j<9 && !f[j])
                        j++; // 找下一个非空子表
                if (f[j]) { // 链接非空子表
                        r[t]->link = f[j];
                        t = e[j];
                }
        }
        r[t]->link = 0;
        // t 指向最后一个非空子表中的最后一个结点
        // 置所有非空子表合并后的链表最后一个结点指针域为 0
}