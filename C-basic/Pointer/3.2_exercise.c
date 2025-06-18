#include <stdio.h>

/**
 * return 如果除法成功返回1,否则返回0
 */

 int divide(int a, int b, int *result);

 int main(void)
 {
    int a = 10;
    int b = 5;
    int c;
    if(divide(a,b,&c))
    {   
        printf("c value is %d\n",*(&c));
        printf("%d/%d = %d\n",a,b,c);//这个c已经被指针赋值了
    }
    return 0;

 }

int divide(int a, int b, int *result)
{   
    int ret = 1;
    if(b ==0) ret = 0;
    
    *result = a/b;//等价于*(&c)
    return ret;

}