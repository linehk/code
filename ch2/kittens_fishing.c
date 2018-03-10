#include <stdio.h>

struct queue {
    int data[1000];
    int head;
    int tail;
};

struct stack {
    int data[10];
    int top;
};

int main() {
    struct queue q1, q2;
    struct stack s;
    int book[10];
    int i, t;

    // init queue
    q1.head = 1; q1.tail = 1;
    q2.head = 1; q2.tail = 1;

    // init stack
    s.top = 0;

    // init book array with 0
    for (i = 1; i <= 9; i++) {
        book[i] = 0;
    }

    // order input 6 numbers to q1
    // xiao heng hand cards
    for (i = 1; i <= 6; i++) {
        scanf("%d", &q1.data[q1.tail]);
        q1.tail++;
    }

    // order input 6 numbers to q2
    // xiao ha hand cards
    for (i = 1; i <= 6; i++) {
        scanf("%d", &q2.data[q2.tail]);
        q2.tail++;
    }

    // loop when queue not empty
    while (q1.head < q1.tail && q2.head < q2.tail) {
        t = q1.data[q1.head]; // xiao heng put a card
        // judge xiao heng this card whether win cards
        if (book[t] == 0) { // tables not t card, so this turn can't win cards
            q1.head++; // put this t card out of queue
            s.top++;
            s.data[s.top] = t; // put t card to tables (in stack)
            book[t] = 1; // mark tables already have t card
        } else {
            // this turn can win cards
            q1.head++; // out of queue
            q1.data[q1.tail] = t; // put t card in hand card at last
            q1.tail++;
            // put tables cards which can win to hand card at last
            while (s.data[s.top] != t) {
                book[s.data[s.top]] = 0; // cancel mark
                q1.data[q1.tail] = s.data[s.top]; // order put to queue-last
                q1.tail++;
                s.top--; // stack lose a card, so stack top - 1
            }
        }

        t = q2.data[q2.head]; // xiao ha put a card
        // judge xiao ha this card whether win cards
        if (book[t] == 0) { // tables not t card, so this turn can't win cards
            q2.head++; // put this t card out of queue
            s.top++;
            s.data[s.top] = t; // in stack
            book[t] = 1; // mark tables already have t card
        } else {
            // this turn xiao ha can win cards
            q2.head++; // put this card out of queue
            q2.data[q2.tail] = t; // add to hand card tail
            q2.tail++;
            // put card in tables which can win to hand card to tail
            while (s.data[s.top] != t) {
                book[s.data[s.top]] = 0; // cancel mark
                q2.data[q2.tail] = s.data[s.top]; // order add to tail
                q2.tail++;
                s.top--;
            }
        }
    }

    if (q2.head == q2.tail) {
        printf("xiao heng win\n");
        printf("xiao heng hands are :");
        for (i = q1.head; i <= q1.tail-1; i++) {
            printf(" %d", q1.data[i]);
        }
        if (s.top > 0) { // order print tables cards
            printf("\ndesk cards are :");
            for (i = 1; i <= s.top; i++) {
                printf(" %d", s.data[i]);
            }
        } else {
            printf("desk out of card!");
        }
    } else {
        printf("xiao ha win\n");
        printf("xiao ha hands are :");
        for (i = q2.head; i <= q2.tail-1; i++) {
            printf(" %d", q2.data[i]);
        }
        if (s.top > 0) { // order print cards in tables
            printf("\ndesk cards are :");
            for (i = 1; i <= s.top; i++) {
                printf(" %d", s.data[i]);
            }
        } else {
            printf("\ndesk out of card!");
        }
    }

    return 0;
}