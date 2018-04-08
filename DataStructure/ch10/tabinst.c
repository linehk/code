#include "table2.h"

// 表插入排序算法
void tableinsertsort(table2 *tab)
{
        int i, p, q;
        tab->r[0].link = 1;
        tab->r[1].link = 0; // 第 1 个元素为有序静态表
        for (i = 2; i <= tab->length; i++) {
                q = 0;
                p = tab->r[0].link; // p 指向表中第 1 个元素，q 指向 p 的前驱元素位置
                while (p!=0 && tab->r[i].key>=tab->r[p].key) { // 找插入位置
                        q = p;
                        p = tab->r[p].link; // 继续查找
                }
                tab->r[i].link = p;
                tab->r[q].link = i; // 将第 i 个元素插入 q 和 p 所指向的元素之间
        }
}