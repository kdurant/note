#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node* next;
}Node;

// LinkList是指向struct Node类型数据的指针变量
// 可以暂时不考虑结构体里的next指针
typedef struct Node* LinkList;

/**
 * @brief 将链表类型声明为LinkList(struct Node*)，可以通过改变地址，方便的修改list指向的结点
 *        test 是链表的头指针而已, 移动头指针指向链表的具体结点
 */
extern LinkList test;

/**
 * @brief 
 * LinkList*list == struct Node* * list, 这里是个二级指针， list是个指向struct Node*变量的指针变量
 * 初始化的工作：
 * 1. 给头结点申请内存空间
 * 2. 将头结点的指针域设置为NULL
 * 3. 将头指针和头结点关联起来
 * 
 * 为什么不将函数原型声明为void list_init(LinkList l) ?
 * 我们需要改变调用程序的变量，只好选择传递指针
 * @param list 
 */
bool list_init(LinkList* l);

/**
 * @brief 在当前链表的末尾追加新的结点
 * 
 * @param l 
 * @param node 
 * @return true 
 * @return false 
 */
bool list_append(LinkList* l, ElemType node);

/**
 * @brief 在链表的第pos个结点后插入新的结点
 * 
 * @param l 
 * @param pos 
 * @param node 
 * @return true 
 * @return false 
 */
bool list_insert(LinkList* l, int pos, ElemType node);

/**
 * @brief 输出链表中每个结点的数据
 * 为什么不使用(LinkList * l)作为参数? 遍历链表时,不需要修改链表的相关信息
 * @param l 
 */
void list_print(LinkList l);

/**
 * @brief 
 * 
 * @param l 
 * @return int 列表已有结点个数(包含头指针)
 */
int list_length(LinkList l);

#endif