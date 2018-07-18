#include <stdio.h>
#include <ctype.h>

#define MAXWORD 100
#define NDISTINCT 1000

struct tnode {                  /* the tree node: */
        char *word;             /* point to the text */
        int count;              /* number of occurrences */
        struct tnode *left;     /* left child */
        struct tnode *right;    /* right child */
};

struct tnode *addtree(struct tnode *, char *);
int getword(char *, int);
void sortlist(void);
void treestore(struct tnode *);

struct tnode *list[NDISTINCT];  /* pointers to tree nodes */
int ntn = 0;    /* number of tree nodes */

/* print distinct words sorted in decreasing order of freq. */
main()
{
        struct tnode *root;
        char word[MAXWORD];
        int i;

        root = NULL;
        while (getword(word, MAXWORD) != EOF)
                if (isalpha(word[0]))
                        root = addtree(root, word);
        treestore(root);
        sortlist();
        for (i = 0; i < ntn; i++)
                printf("%2d:%20s\n", list[i]->count, list[i]->word);
        return 0;
}

/* treestore: store in list[] pointers to tree nodes */
void treestore(struct tnode *p)
{
        if (p != NULL) {
                treestore(p->left);
                if (ntn < NDISTINCT)
                        list[ntn++] = p;
                treestore(p->right);
        }
}

/* sortlist: sort list of pointers to tree nodes */
void sortlist()
{
        int gap, i, j;
        struct tnode *temp;
        for (gap = ntn/2; gap > 0; gap /= 2)
                for (i = gap; i < ntn; i++)
                        for (j = i-gap; j >= 0; j -= gap) {
                                if ((list[j]->count) >= (list[j+gap]->count))
                                        break;
                                temp = list[j];
                                list[j] = list[j+gap];
                                list[j+gap] = temp;
                        }
}