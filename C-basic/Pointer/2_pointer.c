#include <stdio.h>

void f(int *p);
void g(int k);

int main(void)
{
    int i;//等价i = 0;
    int * p = &i;//右代表assignmnt，左代表initialization
    printf("p address is %p\n",&p);
    printf("i address is %p\n",&i);
    printf("i address is %p\n",p);
    printf("i value is %d\n",(*p));


//指针作为参数
int j = 6;
printf("&j=%p\n",&j);
f(&j);
g(j);//只是拿到6，没有改变j的值
printf("j value is %d\n",j);


int k = 6;
scanf("%d",&k);


return 0;

}

void f(int *p)
{
    printf("p=%p\n",p);
    printf("*p=%d\n",*p);

    //试着写入，借此改变j
    *p = 100;
}

//g函数参数是值，不是指针。它没有与变量建立联系
void g(int k)
{   
    k++;
    printf("k= %d\n",k);
}