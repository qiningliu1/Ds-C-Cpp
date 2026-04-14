#include <stdio.h>

int main(void)
{
    //sizeof(char)=1
    char ac[] = {0,1,2,3,4,5,6,7,8,9};
    char *p = ac;
    char *pp =p;//类型相同可赋值
    int *ppp = pp;//类型不同不可赋值,你一个int四个字节，后续做修改相当于一次性改
    //char四个单位
    
    printf("pp address is = %p\n",pp);
    //p++;//向后挪动一位
    printf("p = %p\n",p);
    printf("p+1 = %p\n",p+1);
    printf("p[0] = %d\n",p[0]);
    printf("p[1] value= %d\n",p[1]);
    printf("p[1] address= %p\n",&p[1]);

    //sizeof(int)=4
    int ai[] = {0,1,2,3,4,5,6,7,8,9};
    int *q = ai;
    printf("q = %p\n",q);
    printf("q+1 = %p\n",q+1);
    printf("q[0] = %d\n",q[0]);
    printf("q[1] value= %d\n",q[1]);
    printf("q[1] address= %p\n",&q[1]);
    return 0;
}