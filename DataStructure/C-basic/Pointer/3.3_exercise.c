#include <stdio.h>

/**
 * 常见错误
 */

 void f(int *p);
 void g(int k);

 int main(void)
 {
    int i = 6;
    // int *p;//没有初始化，让它等于任何地址
    // int k;
    // k = 12;
    // *p = 12;//严重错误

int *p;
printf("%d",*p);//报错


    printf("&i = %p\n",&i);
    f(&i);
    g(i);

    return 0;
 }

 void f(int *p)
 {
    printf(" p = %p\n",p);
    printf(" &p = %p\n",&p);
    printf("*p = %d\n",*p);
    *p = 26;
 }

 void g(int k)
 {
    printf(" k= %d\n",k);
 }