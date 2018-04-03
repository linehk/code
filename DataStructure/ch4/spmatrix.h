// 稀疏矩阵的头文件
typedef struct {
        int data[100][100]; // 存放稀疏矩阵的二维数组
        int m, n; // 分别存放稀疏矩阵的行数和列数
} matrix;
typedef int spmatrix[100][3];