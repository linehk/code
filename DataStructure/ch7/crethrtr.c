#include <stdio.h>
#include <stdlib.h>
#include "threadtr.h"

// 创建中序穿线二叉树

binthrtree pre = NULL; // 初始化前驱

// 按前序遍历顺序建立二叉树
binthrtree createbintree()
{
        char ch;
        binthrtree t;
        if ((ch=getchar()) == '#') { // 所建立的二叉树为空二叉树
                t = NULL;
        } else {
                t = (binthrtree*)malloc(sizeof(binthrnode)); // 生成根结点
                t->data = ch;
                t->lchild = createbintree(); // 创建左子树
                t->rchild = createbintree(); // 创建右子树
        }
        return t;
}

// 对二叉树进行中序线索化
void inthreading(binthrtree *p)
{
        if (*p) {
                inthreading(&((*p)->lchild)); // 中序线索化左子树
                (*p)->ltag = ((*p)->lchild) ? 0 : 1; // 对当前结点及其前驱结点进行穿线
                (*p)->rtag = ((*p)->rchild) ? 0 : 1;
                if (pre) {
                        if (pre->rtag == 1)
                                pre->rchild = *p;
                        if ((*p)->ltag == 1)
                                (*p)->lchild = pre;
                }
                pre = *p;
                inthreading(&((*p)->rchild)); // 中序线索化右子树
        }
}

// 创建中序穿线二叉树
void createthrtree(binthrtree *p)
{
        *p = createbintree();
        inthreading(p);
}

int main()
{
        binthrtree root;
        createthrtree(&root);
}