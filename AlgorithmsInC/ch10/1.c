#define bitsword 32
#define bitsbyte 8
#define bytesword 4
#define R (1 << bitsbyte)
#define digit(A, B) (((A) >> (bitsword-((B)+1) * bitsbyte)) & (R-1))

// 二进制快速排序

quicksortB(int a[], int l, int r, int w)
{
        int i = l;
        int j = r;
        if (r <= l || w > bitsword) {
                return;
        }
        while (j != i) {
                while (digit(a[i], w) == 0 && (i < j)) {
                        i++;
                }
                while (digit(a[j], w) == 1 && (j > i)) {
                        j--;
                }
                exch(a[i], a[j]);
        }
        if (digit(a[r], w) == 0) {
                j++;
        }
        quicksortB(a, l, j-1, w+1);
        quicksortB(a, j, r, w+1);
}

void sort(Item a[], int l, int r)
{
        quicksortB(a, l, r, 0);
}