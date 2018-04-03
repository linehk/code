#include <stdio.h>

#define MAXSIZE 20
typedef int listarr[MAXSIZE];

// 按中点优先的顺序遍历线性表 (递归)
// 将数组段 list[left...right] 中的元素按中点优先的顺序输出
void listorder(listarr list, int left, int right)
{
        int mid;
        if (left < right) { // 数组段不为空
                mid = (left+right) / 2;
                printf("%4d", list[mid]); // 取中点元素的值并输出
                listorder(list, left, mid-1);
                // 将中点左部的所有元素按中点优先的顺序输出
                listorder(list, mid+1, right);
                // 将中点右部的所有元素按中点优先的顺序输出
        }
}
