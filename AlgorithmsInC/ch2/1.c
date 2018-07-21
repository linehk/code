// 顺序搜索算法

int search(int a[], int v, int l, int r)
{
        int i;

        for (i = 0; i <= r; i++) {
                if (v == a[i]) {
                        return i;
                }
        }
        return -1;
}