#include<stdio.h>

int main()
{
    int x;
    x = 6;
    printf("sizeof(int)=%ld\n",sizeof(int));
    printf("sizeof(double)=%ld\n",sizeof(double));
    printf("sizeof(int)=%ld\n",sizeof(x));

//输出地址
int i =0;

int p;
p = (int)&i;

// p = (int)&(++i);//报错
// p = (int)&(i + p);//报错
//i + p 也是一个 表达式结果（右值），结果不是一个有名字的变量，所以不能取地址。


//注意我们64位架构输出的是不同，高位被截断，32位架构输出的是相同
//指针在64位架构中占8字节，在32位架构中只占4字节
printf("0x%x\n",p);//%x用来打印unsigned int
printf("%p\n",&i);//%p用来打印void *类型的数据



//1. 变量的地址与相邻变量地址
// int a = 0;
// int b;

// printf("%p\n",&a);
// printf("%p\n",&b);


//根据终端打印可以发现地址相邻且相差4字节，
//后声明的变量地址比前一个变量地址大4字节，栈内存分配原则。

//2. 数组地址

int a[10];
// int b[10];
// b = a;//错误

printf("%p\n",&a);
printf("%p\n",a);//把a数组变量名字直接交给printf函数，相当于把a数组首地址给了printf函数

printf("%p\n",&a[0]);
printf("%p\n",&a[1]);//相邻数组元素地址相差4字节


return 0;

}