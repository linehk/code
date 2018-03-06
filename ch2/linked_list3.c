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
    head = NULL; // init ptr head to NULL

    // loop input n numbers
    for (i = 1; i <= n; i++) {
        scanf("%d", &a);

        // dynamic allocation some space for a node
        // and make *p point to this node
        p = (struct node *)malloc(sizeof(struct node));
        // save a to current node data area
        p -> data = a;
        // set current node next ptr point to NULL
        // that is set current node next node to NULL
        p -> next = NULL;
        if (head == NULL) {
            head = p; // if this node is first create, ptr head point this node
        } else {
            q -> next = p; // if not first create, pre ptr point to current node
        }
        q = p; // *q point to current node
    }

    scanf("%d", &a); // input numbers for insert
    t = head; // loop from linked_list head
    while (t != NULL) { // loop when didn't reach linked_list tail

        // if current node next node value > insert
        // insert to middle
        if (t -> next -> data > a) {
            // dynamic allocation space for new node
            p = (struct node *)malloc(sizeof(struct node));
            p -> data = a;
            //TOOD // new node next ptr point to current node next 
            p -> next = t -> next;
            // current node next ptr point to new node
            t -> next = p;
            // insert already quit loop
            break;
        }
        // continue next node
        t = t -> next;
    }

    // print all numbers of linked_list 
    t = head;
    while (t != NULL) {
        printf("%d ", t -> data);
        t = t -> next; // continue next node
    }
    return 0;
}