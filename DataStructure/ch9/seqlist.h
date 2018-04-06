// 线性表的顺序存储结构
#include <stdio.h>
#define maxsize 1000 // 预定义最大的数据域空间
typedef int datatype; // 假设数据类型为整型
typedef struct {
        datatype data[maxsize]; // 此处假设数据元素只包含一个整型的关键字域
        int len; // 线性表长度
} seqlist; // 预定义的顺序表类型