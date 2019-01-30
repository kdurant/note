#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

int main(void)
{
    Stack s;
    s = CreateStack();
    Push(10, s);
    Push(20, s);
    Push(30, s);

    // printf("hello world\n");
    printf("%d\n", Top(s));
    Pop(s);
    printf("%d\n", Top(s));
    printf("%d\n", Top(s));
}