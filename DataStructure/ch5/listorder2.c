#include <stdio.h>

#define MAXSIZE 20
typedef int listarr[MAXSIZE];

// 按中点优先的顺序遍历线性表 (非递归)
// 将数组段 list[left...right] 中的元素按中点优先的顺序输出
void listorder(listarr list, int left, int right)
{
        typedef struct {
                int l; // 存放等待处理的数组段的起点下标
                int r; // 存放等待处理的数组段的终点下标
        } stacknode; // 栈中每个元素的类型
        stacknode stack[MAXSIZE]; // 用于存放等待处理的数组段(即回溯点)的堆栈
        int top, i, j, mid; // top 为栈顶指针
        if (left <= right) { // 数组段不为空
                top = 0; // 栈的初始化
                i = left;
                j = right; // i j 分别记录当前正在处理的数组段的起点和终点下标
        }
        while (i<=j || top!=0) { // 当前正在处理的数组段不为空或栈不为空
                if (i <= j) { // 当前正在处理的数组段不为空，则遍历它
                        mid = (i+j) / 2;
                        printf("%4d", list[mid]); // 将当前正在处理的数组段中点输出
                        stack[top].l = mid + 1; // 将当前正在处理的数组段中点的右部进栈
                        stack[top].r = j;
                        ++top;
                        j = mid - 1; // 将中点的左部作为当前即将处理的数组段
                } else { // 当前正在处理的数组段为空时通过栈顶元素进行回溯
                        --top;
                        i = stack[top].l;
                        j = stack[top].r;
                }
        }
}
