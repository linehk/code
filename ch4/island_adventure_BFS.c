#include <stdio.h>

struct note {
    int x;
    int y;
};

int main() {
    struct note que[2501];
    int head, tail;

    int a[51][51];
    int book[51][51] = {0};
    int i, j, k, sum, max = 0, mx, my, n, m, startx, starty, tx, ty;

    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    scanf("%d %d %d %d", &n, &m, &startx, &starty);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    head = 1;
    tail = 1;

    que[tail].x = startx;
    que[tail].y = starty;
    tail++;
    book[startx][starty] = 1;
    sum = 1;
}