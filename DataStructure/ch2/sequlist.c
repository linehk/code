#include <stdio.h>
#include <stdlib.h>
#include "sequlist.h"

// 顺序表的初始化-置空表
void init(sequence_list *slt)
{
        slt->size = 0;
}

// 在顺序表后部插入
void append(sequence_list *slt, datatype x)
{
        if (slt->size == MAXSIZE) {
                printf("顺序表是满的！");
                exit(1);
        }
        slt->a[slt->size] = x;
        slt->size = slt->size + 1;
}

// 打印顺序表各结点值
void display(sequence_list slt)
{
        int i;
        if (!slt.size) {
                printf("\n顺序表是空的!");
        }
        else {
                for (i = 0; i < slt.size; i++)
                        printf("%5d", slt.a[i]);
        }
}

// 判断顺序表是否为空
int empty(sequence_list slt)
{
        return (slt.size == 0 ? 1 : 0);
}

// 查找顺序表中值为 x 的结点位置
int find(sequence_list slt, datatype x)
{
        int i = 0;
        while (i < slt.size && slt.a[i] != x)
                i++;
        return (i < slt.size ? i : -1);
}

// 取得顺序表中第 i 个结点的值
datatype get(sequence_list slt, int i)
{
        if (i < 0 || i >= slt.size) {
                printf("\n指定位置的结点不存在！");
                exit(1);
        }
        else {
                return slt.a[i];
        }
}

// 在顺序表的 position 位置插入值为 x 的结点位置
void insert(sequence_list *slt, datatype x, int position)
{
        int i;
        if (slt->size == MAXSIZE)
                printf("\n顺序表是满的！无法插入！");
        if (position < 0 || position > slt->size) {
                printf("\n指定的插入位置不存在！");
                exit(1);
        }
        for (i = slt->size; i > position; i--)
                slt->a[i] = slt->a[i - 1];
        slt->a[position] = x;
        slt->size++;
}

// 删除顺序表中第 position 位置的结点
void dele(sequence_list *slt, int position)
{
        int i;
        if (slt->size == 0) {
                printf("\n顺序表是空的！");
                exit(1);
        }
        if (position < 0 || position >= slt->size) {
                printf("\n指定的删除位置不存在！");
                exit(1);
        }
        for (i = position; i < slt->size - 1; i++)
                slt->a[i] = slt->a[i + 1];
        slt->size--;
}