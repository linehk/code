// 分块查找算法
#include "seqlist.h"
typedef struct { // 索引表结点类型
        datatype key;
        int address;
} indexnode;

// 分块查找算法
// 索引表为 index[0...m-1]
int IndexSeqSearch(seqlist l, indexnode index[], int m, datatype key)
{
        int i = 0, j, last;
        while (i<m && key>index[i].key)
                i++;
        if (i >= m) {
                return -1;
        } else { // 在顺序表在顺序检索
                if (i == m-1)
                        j = l.len - 1;
                else
                        j = index[i+1].address - 1; // j 初始时指向本块的最后一个结点
                while (j>=index[i].address && key!=l.data[j])
                        j--; // 从后向前逐个查找
                if (j < index[i].address)
                        return -1;
                else
                        return j;
        }
}