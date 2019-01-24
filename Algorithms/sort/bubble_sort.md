冒泡排序算法的运作如下：（从后往前）

1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
> 数值小的放在前面

2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。

3. 针对所有的元素重复以上的步骤，除了最后一个。

4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。


```c
#include <stdio.h>

void bubble_sort(int *data, int len)
{
    int temp;
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-1; j++)
        {
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int a[7] = { 40, 9, 20, 3, 5, 33, 4 };
    bubble_sort(a, 7);

    for (int i = 0; i < 7; i++)
        printf("%d\n", a[i]);
    return 0;
}
```