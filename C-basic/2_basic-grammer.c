#include <stdio.h>//头文件包含

#define PI 3.14159 //宏定义
#define MAX(a,b)\
 ((a)>(b)?(a):(b)) //宏定义


 int add(int a, int b)
 {
    return a + b;
 }


 int main()
 {
    int num1, num2, sum;

    //用户输入3个数
    printf("请输入2个数：");
    scanf("%d %d", &num1, &num2);

//int num1; 是一个整数变量，num1 是值。

// scanf 需要 int *，即地址，才能存数据进去。

// 所以 scanf("%d", &num1) 是正确写法。

    //函数调用
    sum = add(num1,num2);
    printf("和为：%d\n", sum);
    return 0;

 }


 //函数定义,放在这里会隐式调用
 int add1(int a, int b)
 {
    return a + b;
 }