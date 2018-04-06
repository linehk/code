// Huffman 算法
#include <stdio.h>
#include <stdlib.h>
typedef struct node { // huffman 树存储结构
        int data; // 权值
        struct node *lchild, *rchild, *next;
} hufnode;
typedef hufnode *linkhuf;

// 将新结点 s 插入到有序链表 root 中，并保持链表的有序性
linkhuf insert(linkhuf root, linkhuf s)
{
        linkhuf p1, p2;
        if (root == NULL) {
                root = s;
        } else {
                p1 = NULL;
                p2 = root;
                while (p2 && p2->data<s->data) { // 查找插入位置
                        p1 = p2;
                        p2 = p2->next;
                }
                s->next = p2;
                if (p1 == NULL)
                        root = s;
                else
                        p1->next = s;
        }
        return root;
}

// 根据有序链表 root 建立 huffman 树
void creathuffman(linkhuf *root)
{
        linkhuf s, rl, rr;
        while (*root && (*root)->next) {
                rl = *root;
                rr = (*root)->next;
                // 每次从链表头部取下两结点作为新生成结点的左、右子树
                *root = rr->next;
                s = (linkhuf)malloc(sizeof(hufnode)); // 生成新结点
                s->next = NULL;
                s->data = rl->data + rr->data;
                s->lchild = rl;
                s->rchild = rr;
                rl->next = rr->next = NULL;
                *root = insert(*root, s); // 将新结点插入到有序表 root 中
        }
}