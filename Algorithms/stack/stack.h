#ifndef STACK_H
#define STACK_H

#include <string.h>
#include <stdio.h>

typedef int ElementType;

struct Node;

typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif