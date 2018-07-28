// 基于关键字索引统计数组的符号表

#include <stdlib.h>
#include "Item.h"
#include "ST.h"

static Item *st;
static int M = maxKey;

void STinit(int maxN)
{
        int i;
        st = malloc((M+1)*sizeof(Item));
        for (i = 0; i <= M; i++) {
                st[i] = NULLitem;
        }
}

int STcount()
{
        int i, N = 0;
        for (i = 0; i < M; i++) {
                if (st[i] != NULLitem) {
                        N++;
                }
        }
        return N;
}

void STinsert(Item item)
{
        st[key(item)] = item;
}

Item STsearch(Key v)
{
        return st[v];
}

void STdelete(Item item)
{
        st[key(item)] = NULLitem;
}

Item STselect(int k)
{
        int i;
        for (i = 0; i < M; i++) {
                if (st[i] != NULLitem) {
                        if (k-- == 0) {
                                return st[i];
                        }
                }
        }
}

void STsort(void (*visit)(Item))
{
        int i;
        for (i = 0; i < M; i++) {
                if (st[i] != NULLitem) {
                        visit(st[i]);
                }
        }
}