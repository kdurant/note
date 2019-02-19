#include "linklist.h"
struct Node
{
    ElementType Element;
    Position Next;
};

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

List CreatList(void)
{
    List l;
    l = (PtrToNode)malloc(sizeof(struct Node));
    if( l == NULL)
        return NULL;
    l->Next = NULL;
	return l;
}

Position Find(ElementType X, List L)
{
    Position P;

    P = L->Next;

    while(P != NULL && P->Element != X)
    {
        P = P->Next;
    }

    return P;    
}

Position FindPrevious(ElementType X, List L)
{
    Position P;

    P = L;
    while(P->Next != NULL && P->Next->Element != X)
        P = P->Next;
    
    return P;
}

void Delete(ElementType X, List L)
{
    Position P, TmpCell;
    
    P = FindPrevious(X, L);

    if(!IsLast(P, L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;

    TmpCell = malloc(sizeof(struct Node));

    if(TmpCell == NULL)
        printf("out of space\n");
    
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
}

void DeleteList(List L)
{
    Position d;
    Position p = L->Next;
    L->Next = NULL;

    while(p != NULL)
    {
        d = p;
        p = p->Next;
        free(d);
    }
}
