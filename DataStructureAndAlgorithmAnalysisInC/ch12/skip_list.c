#include "skip_list.h"
#include <stdlib.h>
#include "fatal.h"

struct SkipNode
{
        ElementType Element;
        SkipList Right;
        SkipList Down;
};

static Position Bottom = NULL;
static Position Tail = NULL;

SkipList Initialize(void)
{
        SkipList L;

        if (Bottom == NULL)
        {
                Bottom = malloc(sizeof(struct SkipNode));
                if (Bottom == NULL)
                        FatalError("Out of space!!!");
                Bottom->Right = Bottom->Down = Bottom;

                Tail = malloc(sizeof(struct SkipNode));
                if (Tail == NULL)
                        FatalError("Out of space!!!");
                Tail->Element = Infinity;
                Tail->Right = Tail;
        }

        L = malloc(sizeof(struct SkipNode));
        if (L == NULL)
                FatalError("Out of space!!!");
        L->Element = Infinity;
        L->Right = Tail;
        L->Down = Bottom;

        return L;
}

void Output(ElementType Element)
{
        printf("%d\n", Element);
}

SkipList MakeEmpty(SkipList L)
{
        L->Right = Tail;
        L->Down = Bottom;
        return L;
}

Position Find(ElementType Item, SkipList L)
{
        Position Current = L;

        Bottom->Element = Item;
        while (Item != Current->Element)
                if (Item < Current->Element)
                        Current = Current->Down;
                else
                        Current = Current->Right;

        return Current;
}

Position FindMin(SkipList L)
{
        Position Current = L;

        while (Current->Down != Bottom)
                Current = Current->Down;
        
        return Current;
}

Position FindMax(SkipList L)
{
        Position Current = L;

        while (Current->Right->Right != Tail ||
                Current->Down != Bottom)
        {
                if (Current->Right->Right != Tail)
                        Current = Current->Right;
                else
                        Current = Current->Down;
        }

        return Current;
}

SkipList Insert(ElementType Item, SkipList L)
{
        Position Current = L;
        Position NewNode;

        Bottom->Element = Item;
        while (Current != Bottom)
        {
                while (Item > Current->Element)
                        Current = Current->Right;

                if (Current->Element > Current->Down->Right->Right->Element)
                {
                        NewNode = malloc(sizeof(struct SkipNode));
                        if (NewNode == NULL)
                                FatalError("Out of space!!!");
                        NewNode->Right = Current->Right;
                        NewNode->Down = Current->Down->Right->Right;
                        Current->Right = NewNode;
                        NewNode->Element = Current->Element;
                        Current->Element = Current->Down->Right->Element;
                }
                else
                        Current = Current->Down;
        }

        if (L->Right != Tail)
        {
                NewNode = malloc(sizeof(struct SkipNode));
                if (NewNode == NULL)
                        FatalError("Out of space!!!");
                NewNode->Down = L;
                NewNode->Right = Tail;
                NewNode->Element = Infinity;
                L = NewNode;
        }

        return L;
}

SkipList Remove(ElementType Item, SkipList L)
{
        printf("Remove is unimplemented\n");
        if (Item)
                return L;
        return L;
}

ElementType Retrieve(Position P)
{
        return P->Element;
}