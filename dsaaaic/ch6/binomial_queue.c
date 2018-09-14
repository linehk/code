#include "binomial_queue.h"
#include "fatal.h"

typedef struct BinNode *Position;

struct BinNode
{
        ElementType Element;
        Position LeftChild;
        Position NextSibling;
};

struct Collection
{
        int CurrentSize;
        BinTree TheTrees[MaxTrees];
};

BinQueue Initialize(void)
{
        BinQueue H;
        int i;

        H = malloc(sizeof(struct Collection));
        if (H == NULL)
                FatalError("Out of space!!!");
        H->CurrentSize = 0;
        for (i = 0; i < MaxTrees; i++)
                H->TheTrees[i] = NULL;
        return H;
}

static void DestroyTree(BinTree T)
{
        if (T != NULL)
        {
                DestroyTree(T->LeftChild);
                DestroyTree(T->NextSibling);
                free(T);
        }
}

void Destroy(BinQueue H)
{
        int i;

        for (i = 0; i < MaxTrees; i++)
                DestroyTree(H->TheTrees[i]);
}

BinQueue MakeEmpty(BinQueue H)
{
        int i;

        Destroy(H);
        for (i = 0; i < MaxTrees; i++)
                H->TheTrees[i] = NULL;
        H->CurrentSize = 0;

        return H;
}

BinQueue Insert(ElementType Item, BinQueue H)
{
        BinTree NewNode;
        BinQueue OneItem;

        NewNode = malloc(sizeof(struct BinNode));
        if (NewNode == NULL)
                FatalError("Out of space!!!");
        NewNode->LeftChild = NewNode->NextSibling = NULL;
        NewNode->Element = Item;

        OneItem = Initialize();
        OneItem->CurrentSize = 1;
        OneItem->TheTrees[0] = NewNode;

        return Merge(H, OneItem);
}

ElementType DeleteMin(BinQueue H)
{
        int i, j;
        int MinTree;
        BinQueue DeletedQueue;
        Position DeletedTree, OldRoot;
        ElementType MinItem;

        if (IsEmpty(H))
        {
                Error("Empty binomial queue");
                return -Infinity;
        }

        MinItem = Infinity;
        for (i = 0; i < MaxTrees; i++)
        {
                if (H->TheTrees[i] && H->TheTrees[i]->Element < MinItem)
                {
                        MinItem = H->TheTrees[i]->Element;
                        MinTree = i;
                }
        }

        DeletedTree = H->TheTrees[MinTree];
        OldRoot = DeletedTree;
        DeletedTree = DeletedTree->LeftChild;
        free(OldRoot);

        DeletedQueue = Initialize();
        DeletedQueue->CurrentSize = (1 << MinTree) - 1;
        for (j = MinTree - 1; j >= 0; j--)
        {
                DeletedQueue->TheTrees[j] = DeletedTree;
                DeletedTree = DeletedTree->NextSibling;
                DeletedQueue->TheTrees[j]->NextSibling = NULL;
        }

        H->TheTrees[MinTree] = NULL;
        H->CurrentSize -= DeletedQueue->CurrentSize + 1;

        Merge(H, DeletedQueue);
        return MinItem;
}

ElementType FindMin(BinQueue H)
{
        int i;
        ElementType MinItem;

        if (IsEmpty(H))
        {
                Error("Empty binomial queue");
                return 0;
        }

        MinItem = Infinity;
        for (i = 0; i < MaxTrees; i++)
        {
                if (H->TheTrees[i] && H->TheTrees[i]->Element < MinItem)
                        MinItem = H->TheTrees[i]->Element;
        }

        return MinItem;
}

int IsEmpty(BinQueue H)
{
        return H->CurrentSize == 0;
}

int IsFull(BinQueue H)
{
        return H->CurrentSize == Capacity;
}

BinTree CombineTrees(BinTree T1, BinTree T2)
{
        if (T1->Element > T2->Element)
                return CombineTrees(T2, T1);
        T2->NextSibling = T1->NextSibling;
        T1->LeftChild = T2;
        return T1;
}

BinQueue Merge(BinQueue H1, BinQueue H2)
{
        BinTree T1, T2, Carry = NULL;
        int i, j;

        if (H1->CurrentSize + H2->CurrentSize > Capacity)
                Error("Merge would exceed capacity");

        H1->CurrentSize += H2->CurrentSize;
        for (i = 0, j = 1; j <= H1->CurrentSize; i++, j *= 2)
        {
                T1 = H1->TheTrees[i];
                T2 = H2->TheTrees[i];

                switch(!!T1 + 2 * !!T2 + 4 * !!Carry)
                {
                        case 0:
                        case 1:
                                break;
                        case 2:
                                H1->TheTrees[i] = T2;
                                H2->TheTrees[i] = NULL;
                                break;
                        case 4:
                                H1->TheTrees[i] = Carry;
                                Carry = NULL;
                                break;
                        case 3:
                                Carry = CombineTrees(T1, T2);
                                H1->TheTrees[i] = H2->TheTrees[i] = NULL;
                                break;
                        case 5:
                                Carry = CombineTrees(T1, Carry);
                                H1->TheTrees[i] = NULL;
                                break;
                        case 6:
                                Carry = CombineTrees(T2, Carry);
                                H2->TheTrees[i] = NULL;
                                break;
                        case 7:
                                H1->TheTrees[i] = Carry;
                                Carry = CombineTrees(T1, T2);
                                H2->TheTrees[i] = NULL;
                                break;
                }
        }
        return H1;
}