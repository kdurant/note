#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

int divide(int dividend, int divisor) {
    int num = 0;
    int sign = 0;

    if(dividend >= 0 && divisor > 0)
        sign = 1;
    else if(dividend <= 0 && divisor < 0)
        sign = 1;
    else 
        sign = 0;

    dividend = dividend >= 0 ? dividend : 0 - dividend;
    divisor = divisor > 0 ? divisor : 0 - divisor;


    while( dividend >= divisor)
    {
        dividend -= divisor;
        num = num + 1;
    }
    if (sign == 0)
        num = INT_MIN + (INT_MIN - num);
    return num;
}

int main()
{
    // int nums[] = {0,11,0,3};
    char nums1[] = {'a', 'b', 'c', 'd'};
    printf("%d\n", INT_MAX);
    printf("%d\n", INT_MIN);
    printf("%d\n", divide(10, 3));
    printf("%d\n", divide(10, -3));
    printf("%d\n", divide(-10, 3));
    printf("%d\n", divide(-10, -3));
    printf("%d\n", divide(-1, 1));
    printf("%d\n", divide(-2147483648, -1));
    return 0;
} 