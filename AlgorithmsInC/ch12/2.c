// 符号表客户程序示例

#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "ST.h"

void main(int argc, char *argv[])
{
        int N, maxN = atoi(argv[1]), sw = atoi(argv[2]);
        Key v;
        Item item;
        STinit(maxN);
        for (N = 0; N < maxN; N++) {
                if (sw) {
                        v = ITEMrand();
                } else if (ITEMscan(&v) == EOF) {
                        break;
                }
                if (STsearch(v) != NULLitem) {
                        continue;
                }
                key(item) = v;
                STinsert(item);
        }
        STsort(ITEMshow);
        printf("\n");
        printf("%d keys ", N);
        printf("%d distinct keys\n", STcount());
}