// 画一把尺子的非递归程序

rule(int l, int r, int h)
{
        int i, j, t;
        for (t = 1, j = 1; t <= h; j += j, t++) {
                for (i = 0; l+j+i <= r; i += j+j) {
                        mark(l+j+i, t);
                }
        }
}