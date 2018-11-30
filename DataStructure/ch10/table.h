// 常见排序算法的头文件
#define MAXSIZE 100 // 文件中记录个数的最大值
typedef int keytype; // 定义排序码类型为整数类型
typedef struct {
        keytype key;
        int other; // 此处还可以定义记录中除排序码外的其它域
} recordtype;
typedef struct {
        recordtype r[MAXSIZE+1];
        int length; // 待排序文件中记录的个数
} table; // 待排序文件类型