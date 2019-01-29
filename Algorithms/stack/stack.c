#include "stack.h"

struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

void MakeEmpty(Stack S)
{
    if(S == NULL)
        printf("creat stack\n");
    else
    {
        while(!IsEmpty(S))
        {
            Pop(S);
        }
    }
}
Stack CreateStack(void)
{
    Stack S;
    S = (Stack)malloc(sizeof(struct Node));
    if(S == NULL)
        return NULL;
    S->Next == NULL;
    MakeEmpty(S);
    return S;
}

void Pop(Stack S)
{

}

void Push(ElementType X, Stack S)
{
    PtrToNode temp;
    temp = (PtrToNode)malloc(sizeof(struct Node));

    if(temp == NULL)
        return;
    else
    {
        
    }
    
}