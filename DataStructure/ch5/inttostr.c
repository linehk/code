#include <stdio.h>

// 将正整数 n 转换成字符串
void convert(int n)
{
        int i;
        char ch;
        if ((i=n/10) != 0)
                convert(i);
        ch = (n%10) + '0';
        putchar(ch);
}