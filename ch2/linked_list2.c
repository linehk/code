#include <stdio.h>
#include <stdlib.h>

// create struct for linked_list
struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head, *p, *q, *t;
    int i, n, a;
    scanf("%d", &n);
    head = NULL; // init head ptr NULL

    // loop input n numbers
    for (i = 1; i <= n; i++) {
        scanf("%d", &a);
        // dynamic allocation some space for a node
        // and make *p point to this node
        p = (struct node *)malloc(sizeof(struct node));
        // save a to current node data area
        p -> data = a;
        // set current node next ptr to NULL
        // that is set current node next node to NULL
        p -> next = NULL;
        if (head == NULL) {
            head = p; // if first create node, head ptr point to this node
        } else {
            q -> next = p; // if not first create node, pre ptr point to current node
        }
        q = p; // *q point to current node too
    }

    // print linked_list all numbers
    t = head;
    while (t != NULL) {
        printf("%d ", t -> data);
        t = t -> next; // continue next node
    }
    return 0;
}