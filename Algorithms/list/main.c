#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "list.h"

int main(void)
{
	LinkList test;
    if(list_init(&test))
    {
        printf("link list init success\n");
    }
    
    list_append(&test, 20);
    list_append(&test, 30);
    list_append(&test, 33);
    list_append(&test, 43);
	test = list_reverse(test);
    printf("link list length is %d\n", list_length(test));
    list_print(test);
    //printf("%d\n", list_find_item(test, 33));
    return 0;
}