// 非递归选择算法

select(Item a[], int l, int r, int k)
{
        while (r > l) {
                int i = partition(a, l, r);
                if (i >= k) {
                        r = i - 1;
                }
                if (i <= k) {
                        l = i + 1;
                }
        }
}