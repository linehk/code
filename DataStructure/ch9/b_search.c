// 二分查找算法
#include "seqlist.h"

// 二分查找的非递归实现算法
int binsearch1(seqlist l, datatype key)
{
        int low = 0, high = l.len - 1, mid;
        while (low <= high) {
                mid = (low+high) / 2; // 二分
                if (l.data[mid] == key)
                        return mid; // 检索成功返回
                if (l.data[mid] < key)
                        high = mid - 1; // 继续在前半部分进行二分检索
                else
                        low = mid + 1; // 继续在后半部分进行二分检索
        }
        return -1; // 当 low>high 时表示查找区间为空，检索失败
}

// 二分查找的递归实现算法
int binsearch2(seqlist l, datatype key, int low, int high)
{
        int mid, k;
        if (low > high) {
                return -1; // 检索不成功的出口条件
        } else {
                mid = (low+high) / 2; // 二分
                if (l.data[mid] == key)
                        return mid; // 检索成功返回
                if (l.data[mid] > key)
                // 递归地在前半部分检索
                        return binsearch2(l, key, low, mid-1);
                else
                // 递归地在后半部分检索
                        return binsearch2(l, key, mid+1, high);
        }
}