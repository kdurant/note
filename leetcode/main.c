#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

struct test
{
	char data[4];
};

struct test t =
{
	.data = "2.00"
};

int main()
{
	struct test *p = &t;
	p->data[0] = '4';
    printf("%s\n", t.data);
    return 0;
} 