#include <stdio.h>
int max(int x, int y);

int main(void)
{
    /*p是函数指针*/
    int (*p)(int,int) = max;//&可以省略

    //等价
    printf("max函数地址: %p\n", p);
    printf("max函数地址: %p\n", max);
    printf("max函数地址: %p\n", &max);



    int a, b, c;
    printf("请输入三个数：");
    scanf("%d %d %d",&a,&b,&c);
   
    int d = p(p(a,b),c);
    printf("最大值为：%d\n",d);
    return 0;
}

int max(int x, int y)
{
    return x > y ? x : y;
}