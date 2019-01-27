#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *a;
    *returnSize = 0;
    if(nums1Size >= nums2Size)
        a = (int *)malloc(sizeof(int)*nums2Size);
    else
        a = (int *)malloc(sizeof(int)*nums1Size);

    for(size_t i = 0; i < nums1Size; i++)
    {
        if(i > 1 && (nums1[i] == nums1[i-1]))
            break;
        for(size_t j = 0; j < nums2Size; j++)
        {
            if(nums1[i] == nums2[j])
            {
                a[*returnSize] = nums1[i]; 
                (*returnSize)++;
                break;
            }
        }
    }
    return a;
}

int main()
{
    // int nums[] = {0,11,0,3};
    int nums1[] = {1,2,2,2,1};
    int nums2[] = {2, 2};
    int cnt ;
    intersect(nums1, 5, nums2, 2, &cnt);
    printf("%d\n", cnt);
    return 0;
} 