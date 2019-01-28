#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct ListNode
{
    ElemType data;
    struct ListNode* next;
}ListNode;

// LinkList是指向struct Node类型数据的指针变量
// 可以暂时不考虑结构体里的next指针
typedef struct ListNode* LinkList;

/**
 * @brief test 是链表的头指针而已, 移动头指针指向链表的具体结点
struct Node							
----------------------------------------------------------------
head		    | node1		    | node2		    | node3	
data		    | data	10	    | data	20	    | data	30
next	0x1000	| next	0x2000	| next	0x3000	| next	0x3000
----------------------------------------------------------------
struct Node * test;   // test的值是结点的地址
func(LinkList* l, ElemType node)
 */
extern LinkList test;

/**
 * @brief 
 * 初始化的工作：
 * 1. 给头结点(header or dummy node)申请内存空间
 * 2. 将头结点的指针域设置为NULL
 * 3. 将头指针和头结点关联起来
 * 
 * 头结点的使用是有争议的, 纯属个人兴趣
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
bool list_test(LinkList l, int pos, ElemType node);

/**
 * @brief 删除链表指定位置的结点. 例如链表原有数据为3, 1, 2, 4
 * list_pos_delete(&test, 1)后变成3, 2, 4
 * 
 * @param l 
 * @param pos 
 * @return true 删除成功
 * @return false 删除失败
 */
bool list_pos_delete(LinkList* l, int pos);

/**
 * @brief 输出链表中每个结点的数据
 * 为什么不使用(LinkList * l)作为参数? 遍历链表时,不需要修改链表的相关信息
 * @param l 
 */
void list_print(LinkList l);

/**
 * @brief 查找元素在链表中第一次出现的位置
 * 
 * @param l 
 * @return int 
 */
int list_find_item(LinkList l, ElemType node);

/**
 * @brief 
 * 
 * @param l 
 * @return int 列表已有结点个数(不包含头指针)
 */
int list_length(LinkList l);

bool list_is_empty(LinkList l);

/**
 * @brief 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * @param l1 
 * @param l2 
 * @return LinkList* 
 */
LinkList * mergeTwoLists(LinkList * l1, LinkList* l2);
#endif