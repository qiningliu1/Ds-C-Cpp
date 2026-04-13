#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    //c99
    int number;
    printf("输入数量 ");
    scanf("%d",&number);
    //int a[number];

    //动态内存分配
    int *a;
    int i;
    a = (int*)malloc(number*sizeof(int));
    printf("请依次输入数组元素： \n");
    for(i= 0; i<number;i++){
        scanf("%d",&a[i]);
    }
    for(i = number-1;i>=0;i--){
        printf("第%d个元素 = %d\n",i,a[i]);
    }
    free(a);//有借有还
    return 0;
}