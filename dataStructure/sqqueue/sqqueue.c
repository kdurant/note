#include "sqqueue.h"

#define     MinQueueSize    (5)

struct QueueRecord
{
    int Capacity;   // 队列的最大容量
    int Front;      // 队首，出队
    int Rear;       // 队尾，入队
    int Size;       // 队列里当前元素的个数
    ElementType *Array;
};

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
    Queue q;
    // if(MaxElements < )
    q = (Queue)malloc(sizeof(Queue));
    if( q == NULL)
        printf("out of space\n");
    q->Array = malloc(sizeof(ElementType)*MaxElements);
    if( q == NULL)
        printf("out of space\n");
    
    q->Capacity = MaxElements;
	MakeEmpty(q);

    return q;
}

void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 0;
    Q->Rear = 0;
}

static int Succ(int Value, Queue Q)
{
    if(++Value == Q->Capacity)
        Value = 0;
    return Value;
}

void Enqueue(ElementType X, Queue Q)
{
    if( IsFull(Q))
        printf("queue is full\n");
    else
    {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

ElementType FrontAndDequeue(Queue Q)
{

}