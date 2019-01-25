#include <stdio.h>

void insert_sort(int *nums, int len)
{
    int temp;
    for(size_t i = 1; i < len; i++)
    {
        for(size_t j = i; j > 0; j--)
        { 
            if(nums[j] < nums[j-1] )  // 后一个元素小于前一个元素
            {
                temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
            }
        }
        
    }
    
}

int main()
{
    int nums[6] = {44, 38, 5, 3, 47, 50};
    insert_sort(nums, 6);
    for(size_t i = 0; i < 6; i++)
    {
        printf("%d ", nums[i]);
    }
    
}