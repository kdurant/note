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

Position FindMin(SearchTree T)
{
    if( T == NULL)
        return NULL;
    else
    {
        if(T->Left == NULL)
            return T;
        else 
            return FindMin(T->Left);
    }
}

Position FindMax(SearchTree T)
{
    if( T == NULL)
        while(T->Right != NULL){
            T = T->Right;
        }
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if(T == NULL)
    {
        T = malloc(sizeof(struct TreeNode));
        if(T == NULL)
            printf("out of space\n");
        else 
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if(X < T->Element)
    {
        T->Left = Insert(X, T->Left);
    }
    else
    {
        if( X > T->Element)
            T->Right = Insert(X, T->Right);
    }

    return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpCell;

    if(T == NULL)
        printf("Element not found\n");
    else if(X < T->Element)
        T->Left = Delete(X, T->Left);
    else if(X > T->Element)
    {
        
    }
}