#include <stdio.h>

int main(void)
{

    //c占位符和s占位符的区别
    //c占位符只输出一个字符
    //s占位符输出一个字符串
char *names[] = {"Miller","Jones","Anderson"};
printf("第二个元素第三个字符是%c\n",*(*(names+1)+2));


int num;
int *p = &num;
printf("p的地址为%p\n",p);

}