// 栈 ADT 数组实现类型声明
#ifndef _Stack_h

struct StackRecord;
typedef struct StackRecord *Stack;

typedef int ElementType;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif

#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord
{
        int Capacity;
        int TopOfStack;
        ElementType *Array;
};