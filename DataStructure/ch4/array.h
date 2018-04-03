// 三维数组顺序存储的头文件
typedef int datatype; // 假设数据元素的值为整型
typedef struct {
        datatype *base; // 数组存储的首地址指针
        int index[3]; // 存放三维数组各维的长度
        int c[3]; // 存放三维数组各维的 c[i] 值
} array;