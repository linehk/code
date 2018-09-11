typedef int ElementType;
#define SpaceSize 10
// 链表游标实现
#ifndef _Cursor_H

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpace(void);

List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P, const List L);
Position Find(ElementType X, const List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, const List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(const List L);
Position First(const List L);
Position Advance(const Position P);
ElementType Retrieve(const Position P);

#endif

struct Node
{
        ElementType Element;
        Position Next;
};

struct Node CursorSpace[SpaceSize];

// 分配和回收游标空间
static Position
CursorAlloc(void)
{
        Position P;

        P = CursorSpace[0].Next;
        CursorSpace[0].Next = CursorSpace[P].Next;
        return P;
}

static void
CursorFree(Position P)
{
        CursorSpace[P].Next = CursorSpace[0].Next;
        CursorSpace[0].Next = P;
}