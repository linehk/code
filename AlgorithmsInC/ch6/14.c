// 原位排序

insitu(dataType data[], int a[], int N)
{
        int i, j, k;
        for (i = 0; i < N; i++) {
                dataType v = data[i];
                for (k = i; a[k] != i; k = a[j], a[j] = j) {
                        j = k;
                        data[k] = data[a[k]];
                }
                data[k] = v;
                a[k] = k;
        }
}