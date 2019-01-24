/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
所有输入只包含小写字母 a-z 。
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include<limits.h>

char* longestCommonPrefix(char** strs, int strsSize) 
{
    char* str=(char*)malloc(128);
    memset(str,0,128);
    
    
}

int main()
{
    char *str[3] = {"flower","flow","flight"};
    longestCommonPrefix(str, 3);
    return 0;
}