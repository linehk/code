#include <stdio.h>

int main() {
    // init queue
    int q[102] = {0, 6, 3, 1, 7, 5, 8, 9, 2, 4}, head, tail;
    int i;

    head = 1;

    // queue already have 9 items, tail point to queue-last next
    tail = 10; 

    // loop when queue not empty
    while (head < tail) {

        // print queue-first and make queue-first out of queue
        printf("%d ", q[head]);
        head++;

        // firstly, add new queue-first to queue-last 
        q[tail] = q[head];
        tail++;
        // then, make queue-first out of queue
        head++;
    }

    return 0;
}