#include <stdlib.h>
#include "array.h"

// 三维数组的初始化
int initarray(array *A, int b1, int b2, int b3)
{
        int elements;
        if (b1<=0 || b2<=0 || b3<=0) // 处理非法情况
                return 0;
        A->index[0] = b1;
        A->index[1] = b2;
        A->index[2] = b3;
        elements = b1 * b2 * b3; // 求数组元素的个数
        A->base = (datatype*)malloc(elements*sizeof(datatype)); // 为数组分配空间
        if (!(A->base))
                return 0;
        A->c[0] = b2 * b3;
        A->c[1] = b3;
        A->c[2] = 1;
        return 1;
}