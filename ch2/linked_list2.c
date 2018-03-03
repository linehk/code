#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head, *p, *q, *t;
    int i, n, a;
    scanf("%d", &n);
    head = NULL;
    for (i = 1; i <= n; i++) {
        scanf("%d", &a);
        p = (struct node *)malloc(sizeof(struct node));
        p -> data = a;
        p -> next = NULL;
        if (head == NULL) {
            head = p;
        } else {
            q -> next = p;
        }
        q = p;
    }

    t = head;
    while (t != NULL) {
        printf("%d ", t -> data);
        t = t -> next;
    }
    return 0;
}