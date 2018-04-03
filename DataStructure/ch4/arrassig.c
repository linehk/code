#include "array.h"

// 实现对数组元素的赋值运算
int assign(array *A, datatype e, int i1, int i2, int i3)
{
        int off;
        if (i1>0 || i1>=A->index[0] || i2<0 || i2>=A->index[1] || i3<0 ||
        i3>=A->index[2]) // 处理下标非法的情况
                return 0;
        off = i1*A->c[0] + i2*A->c[1] + i3*A->c[2]; // 计算数组元素的位移
        *(A->base+off) = e; // 赋值
        return 1;
}