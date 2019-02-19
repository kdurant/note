#ifndef LINKLIST_H
#define LINKLIST_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
List CreatList(void);

/**
 * @brief 返回元素在链表中的位置
 * 
 * @param X 
 * @param L 
 * @return Position 
 */
Position Find(ElementType X, List L);

/**
 * @brief 删除链表中第一次出现X的结点. 如果表中没有X, 则什么都不做
 * 
 * @param X 
 * @param L 
 */
void Delete(ElementType X, List L);

/**
 * @brief 返回元素在链表中的前驱元位置
 * 
 * @param X 
 * @param L 
 * @return Position 
 */
Position FindPrevious(ElementType X, List L);

/**
 * @brief 将元素X插入到P所示的位置之后
 * 
 * @param X 
 * @param L 
 * @param P 
 */
void Insert(ElementType X, List L, Position P);

void DeleteList(List L);

Position Header(List L);

Position First(List L);

Position Advance(Position P);

ElementType Retrieve(Position P);

#endif