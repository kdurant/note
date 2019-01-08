#include <stdio.h>
#include "squeue.h"

LinkQueue q;
int main(void)
{
    InitQueue(&q);
    int i;
    if (QueueEmpty(q))
        printf("queue is empty\n");
    else
        printf("queue is not empty\n");
    EnQueue(&q, 20);
    printf("queue length is %d\n", QueueLength(q));
    EnQueue(&q, 30);
    printf("queue length is %d\n", QueueLength(q));
    EnQueue(&q, 40);
    printf("queue length is %d\n", QueueLength(q));
    EnQueue(&q, 50);
    printf("queue length is %d\n", QueueLength(q));

    if (QueueEmpty(q))
        printf("queue is empty\n");
    else
        printf("queue is not empty\n");

    DeQueue(&q, &i);
    printf("output data is %d\n", i);
    printf("queue length is %d\n", QueueLength(q));
    DeQueue(&q, &i);
    printf("output data is %d\n", i);
    printf("queue length is %d\n", QueueLength(q));
}