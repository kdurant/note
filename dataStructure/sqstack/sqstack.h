
#ifndef SQSTACK_H
#define SQSTACK_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;
struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);

/**
 * @brief 释放栈. 先释放数组, 然后释放栈结构体
 * 
 * @param S 
 */
void DisposeStack(Stack S);

void MakeEmpty(Stack S);

void Push(ElementType X, Stack S);

/**
 * @brief 返回栈顶的当前元素, 并不删除
 * 
 * @param S 
 * @return ElementType 
 */
ElementType Top(Stack S);

/**
 * @brief 改变栈顶指针, 却没有返回数据
 * 不是很明白
 * @param S 
 */
void Pop(Stack S);

/**
 * @brief 返回栈顶的当前元素, 并将栈顶指针减一
 * 
 * @param S 
 * @return ElementType 
 */
ElementType TopAndPop(Stack S);

#endif