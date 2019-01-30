#include "linkstack.h"

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

/**
 * @brief Create a Stack object
 * 带有头结点
 * @return Stack 
 */
Stack CreateStack(void)
{
    Stack S;
    S = (Stack)malloc(sizeof(struct Node));
    if(S == NULL)
        return NULL;
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void Pop(Stack S)
{
    PtrToNode FirstCell;

    if(IsEmpty(S))
        return;
    else
    {
        FirstCell = S->Next;    // 保存带删除结点, 防止内存泄漏
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}

void Push(ElementType X, Stack S)
{
    PtrToNode temp;
    temp = (PtrToNode)malloc(sizeof(struct Node));

    if(temp == NULL)
        return;
    else
    {
        // 拥有头指针
        temp->Element = X;
        temp->Next = S->Next;
        S->Next = temp;
    } 
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Next->Element;
    else
        return 0;
}