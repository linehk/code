// 队列 (顺序存储) 的头文件
#define MAXSIZE 100
typedef int datatype;
typedef struct {
        datatype a[MAXSIZE];
        int front;
        int rear;
} sequence_queue;