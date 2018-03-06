// struct achieve queue

#include <stdio.h>

struct queue {
    int data[100]; // main of queue, store for value
    int head; // queue-first
    int tail; // queue-last
};

int main() {
    struct queue q;
    int i;

    // init queue
    q.head = 1;
    q.tail = 1;
    for (i = 1; i <= 9; i++) {
        // order insert 9 numbers to queue
        scanf("%d", &q.data[q.tail]);
        q.tail++;
    }

    // loop when queue not empty
    while (q.head < q.tail) {
        // print queue-first and make queue-first out of queue
        printf("%d ", q.data[q.head]);
        q.head++;

        // firstly, add new queue-first numbers to queue-last
        q.data[q.tail] = q.data[q.head];
        q.tail++;

        // then, make queue-first out of queue
        q.head++;
    }

    return 0;
}