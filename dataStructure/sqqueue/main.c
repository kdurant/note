#include "sqqueue.h"

int main()
{
    Queue q;

    q = CreateQueue(10);
    Enqueue(10, q);
    Enqueue(20, q);
    Enqueue(20, q);
}