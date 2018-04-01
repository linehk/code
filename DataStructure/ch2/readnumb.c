// 将数字字符串转变成对应的数
double readnumber(char f[], int *i)
{
        double x = 0.0;
        int k = 0;
        while (f[*i] >= '0' && f[*i] <= '9') { // 处理整数部分
                x = x * 10 + (f[*i] - '0');
                (*i)++;
        }
        if (f[*i] == '.') { // 处理小数部分
                (*i)++;
                while (f[*i] >= '0' && f[*i] <= '9') {
                        x = x * 10 + (f[*i] - '0');
                        (*i)++;
                        k++;
                }
        }
        while (k != 0) {
                x = x / 10.0;
                k = k - 1;
        }
        return x;
}