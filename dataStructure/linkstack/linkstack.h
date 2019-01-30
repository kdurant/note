#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct Node;

typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);

/**
 * @brief 向链表前端插入元素
 * 
 * @param X 
 * @param S 
 */
void Push(ElementType X, Stack S);

/**
 * @brief 返回栈顶的当前元素, 并不删除
 * 
 * @param S 
 * @return ElementType 
 */
ElementType Top(Stack S);

/**
 * @brief 从栈顶弹出元素
 * 
 * @param S 
 */
void Pop(Stack S);

#endif