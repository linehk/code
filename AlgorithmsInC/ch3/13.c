// 约瑟夫问题的链表分配

#include "list.h"

main(int argc, char *argv[])
{
        int i, N = atoi(argv[1]), M = atoi(argv[2]);
        Node t, x;
        initNodes(N);

        for (i = 2, x = newNode(1); i <= N; i++) {
                t = newNode(i);
                insertNext(x, t);
                x = t;
        }
        while (x != Next(x)) {
                for (i = 1; i < M; i++) {
                        x = Next(x);
                }
                freeNode(deleteNext(x));
        }
        printf("%d\n", Item(x));
}