#include "sqstack.h"

int main()
{
    Stack s;
    s = CreateStack(10);
    
    Push(10, s);
    Push(20, s);
    Push(30, s);

    printf("%d\n", TopAndPop(s));
    printf("%d\n", TopAndPop(s));

    printf("%d\n", TopAndPop(s));

    printf("%d\n", TopAndPop(s));


    printf("%d\n", Top(s));
}