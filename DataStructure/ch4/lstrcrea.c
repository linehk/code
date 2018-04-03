#include <stdio.h>
#include <stdlib.h>
#include "linkstr.h"

// 链式串的创建
void strcreate(linkstring *S)
{
        char ch;
        linkstrnode *p, *r;
        *S = NULL;
        r = NULL; // 用 r 始终指向当前链式串的最后一个字符对应的结点
        while ((ch=getchar()) != '\n') {
                p = (linkstrnode*)malloc(sizeof(linkstrnode)); // 产生新结点
                p->data = ch;
                if (*S == NULL) // 新结点插入空表的情况
                        *S = p;
                else // 新结点插入非空表的情况
                        r->next = p;
                r = p; // r 移向当前链式串的最后一个字符的位置
        }
        if (r != NULL)
                r->next = NULL; // 处理表尾结点指针域
}