#include "sqstack.h"

#define EmptyTos        (-1)
#define MinStackSize    (5)

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};


Stack CreateStack(int MaxElements)
{
    Stack S;
    if(MaxElements < MinStackSize)
        printf("Stack size is too small\n");
    
    S = (Stack)malloc(sizeof(Stack));
    if( S == NULL)
        printf("out of space\n");
    
    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if(S->Array == NULL)
        printf("out of space\n");
    
    S->Capacity = MaxElements;
    MakeEmpty(S);
    
    return S;
}

void DisposeStack(Stack S)
{
    if(S != NULL)
    {
        free(S->Array);
        free(S);
    }
}

int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTos;
}

int IsFull(Stack S)
{
    return S->TopOfStack == S->Capacity;
}
void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTos;
}

void Push(ElementType X, Stack S)
{
    if(IsFull(S))
        printf("stack is full\n");
    
    S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack];
    else
        return 0;
}

void Pop(Stack S)
{
    if(IsEmpty(S))
        printf("stack is empty\n");
    else
        S->TopOfStack--;
}

ElementType TopAndPop(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack--];
    
    return 0;
}