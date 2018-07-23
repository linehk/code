// 字符串元素的数据类型实现

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"

static char buf[100000];
static int cnt = 0;

int ITEMscan(char **x)
{
        int t;
        *x = &buf[cnt];
        t = scanf("%s", *x);
        cnt += strlen(*x)+1;
        return t;
}

void ITEMshow(char *x)
{
        printf("%s ", x);
}