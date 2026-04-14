#include <stdio.h>
#include <stdlib.h>

int main()

{
    /*初始化数组*/
    //栈上申请内存
    int arr[5];//未初始化，得到垃圾值
    printf("arr address: %p\n",arr);
    for(int i = 0;i<5;i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }
    int num[5] = {0};
    printf("num address: %p\n",num);
    for(int i = 0;i<5;i++)
    {
        printf("num[%d] = %d\n",i,num[i]);
    }

    //存储在堆上
    int *arr2 = (int *)malloc(sizeof(int)*5);
    printf("arr2 address: %p\n",arr2);
    for(int i = 0;i<5;i++)
    {
        printf("arr2[%d] = %d\n",i,arr2[i]);
    }
    free(arr2);
    //有趣的是我们发现arr2的地址没有变化，值也没有被清理
    //实际上这里只是被标记为可重用内存，后续仍然需要我们将指针置空，避免悬空指针
    printf("arr2 address: %p\n",arr2);

    for(int i = 0;i<5;i++)
    {
        printf("arr2[%d] = %d\n",i,arr2[i]);
    }
    arr2 = NULL;
}