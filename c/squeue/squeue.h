 #ifndef SQUEUE_H
#define SQUEUE_H

// 链式队列

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef int QElemType;

// QNode == struct QNode
// QueuePtr = struct QNode *
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode, * QueuePtr;

typedef struct          /* 队列的链表结构 */
{
    QueuePtr front; // 队头指针
    QueuePtr rear;  // 队尾指针
} LinkQueue;

/**
 * @brief 
 * 
 * @param Q 
 * @return true 
 * @return false 
 */
bool InitQueue(LinkQueue *Q);

bool QueueEmpty(LinkQueue Q);

// 入队
bool EnQueue(LinkQueue *Q, QElemType e);

// 出队
bool DeQueue(LinkQueue *Q, QElemType *e);

int QueueLength(LinkQueue Q);

#endif // 