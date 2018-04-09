// 链式基数排序头文件
#define N 20 // 设待排序的记录个数为 20
#define B 5 // 设排序码最多为 5 位数
typedef struct {
        int key[B+1]; // key[i] 为排序码从右到左 (最低位) 开始的第 i 位数
        int link; // 指针域
} node;
typedef node list[N+1];
typedef int staticlist[10];
staticlist f, e;