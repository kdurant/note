#include "tree.h"

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T)
{
    if( T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find( ElementType X, SearchTree T)
{
    if( T == NULL)
        return NULL;
    
    if(X < T->Left)
        return Find(X, T->Left);
    else if(X > T->Left)
        return Find(X, T->Right);
    else 
        return T;
}
