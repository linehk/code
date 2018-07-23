// 使用分治法在尺子上画刻度

rule(int l, int r, int h)
{
        int m = (l+r) / 2;
        if (h > 0) {
                rule(l, m, h-1);
                mark(m, h);
                rule(m, r, h-1);
        }
}