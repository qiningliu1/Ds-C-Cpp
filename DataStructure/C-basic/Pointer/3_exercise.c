/**
 * 指针应用场景
 */

 #include<stdio.h>

 void swap(int *pa,int *pb);

 int main(void)
 {
    int a = 5;
    int b = 6;
    swap(&a,&b);
    printf("a = %d\n",a);
    printf("b = %d\n",b);



    //只能在main函数中交换c,d
    //出了main进入外部函数就没效果了
    int c = 5;
    int d=7;

    int temp = c;
    c = d;
    d = temp;
    printf("c = %d\n",c);
    printf("d = %d\n",d);

    return 0;
 }




 void swap(int *pa,int *pb)
 {
    int t = *pa;
    *pa = *pb;
    *pb = t;
 }

