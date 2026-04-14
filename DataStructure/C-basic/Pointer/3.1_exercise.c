/**
 * 两个或多个结果无法通过返回值返回的场景
 */


#include <stdio.h>
void minmax(int a[], int len, int *min, int* max);

int main(void) 
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int max, min;
    printf("min address = %p,max address = %p\n",&min,&max);
    minmax(a, sizeof(a)/sizeof(a[0]), &max, &min);
    printf("min = %d, max = %d, len = %ld\n", min, max,sizeof(a)/sizeof(a[0]));
    return 0;
}

void minmax(int a[], int len, int *max, int* min)
{
    int i;
    *min = *max = a[0];//这里是赋值
    for (i = 1; i < len; i++)
    {
        if (a[i] > *max)
            *max = a[i];
        else if (a[i] < *min)
            *min = a[i];
    }
    
}