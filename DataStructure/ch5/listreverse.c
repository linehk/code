#include "sequence.h"

// 将顺序表中的元素值进行逆转 (递归)
// 将顺序表 L 中从下标为 left 的元素开始到下标为 right 的元素构成的子数组进行逆转
void reverse1(sequence_list *L, int left, int right)
{
        datatype temp;
        if (left < right) {
                reverse1(L, left+1, right-1);
                temp = L->a[left];
                L->a[left] = L->a[right];
                L->a[right] = temp;
                // 将下标为 left 的元素和下标为 right 的元素的值进行交换
        }
}

// 将顺序表中的元素值进行逆转 (非递归)
// 将顺序表 L 中从下标为 left 的元素开始到下标为 right 的元素构成的子数组进行逆转
void reverse2(sequence_list *L, int left, int right)
{
        datatype temp;
        while (left < right) {
                temp = L->a[left];
                L->a[left++] = L->a[right];
                L->a[right--] = temp;
                // 将下标为 left 的元素和下标为 right 的元素的值进行交换
        }
}