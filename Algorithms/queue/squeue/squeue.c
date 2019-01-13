#include "squeue.h"

bool InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));

    if (!Q->front)
        return false;
	// 上面已将Q->front和Q->rear指向同一个内存地址，这里会同时将Q->front->next和Q->rear->next指向空
    Q->front->next = NULL;
        return true;
}

bool EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));		// 队列节点
    if (!s) /* 存储分配失败 */
        return false;
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;  // 把拥有元素e的新结点s赋值给原队尾结点的后继
    Q->rear = s;        // 把当前的s设置为队尾结点，rear指向s
    return true;
}

bool DeQueue(LinkQueue *Q, QElemType *e)
{
    QueuePtr p;
    if (Q->front == Q->rear)
        return false;
    p = Q->front->next;     /* 将欲删除的队头结点暂存给p */
    *e = p->data;              /* 将欲删除的队头结点的值赋值给e */
    Q->front->next = p->next;/* 将原队头结点的后继p->next赋值给头结点后继 */
    if (Q->rear == p)       /* 若队头就是队尾，则删除后将rear指向头结点 */
        Q->rear = Q->front;
    free(p);
    return true;
}

int QueueLength(LinkQueue Q)
{
    int i = 0;
    QueuePtr p;
    p = Q.front;
    while (Q.rear != p)
    {
        i++;
        p = p->next;
    }
    return i;
}

bool QueueEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}