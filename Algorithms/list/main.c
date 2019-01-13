#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "list.h"

int main(void)
{
    if(list_init(&test))
    {
        printf("link list init success\n");
    }
    
    list_append(&test, 20);
    // list_print(test);
     list_append(&test, 30);
    printf("link list length is %d\n", list_length(test));
    list_print(test);
    return 0;
}