#include<stdio.h>

struct point {
    int x;
    int y;
};

struct point getStruct(void);
void output(struct point);

int main(int argc,char const *argv[])
{
    struct point y = {0,0};
    // getStruct(y);
    y = getStruct();
    output(y);
}

//原先这个写法不改变原始y的值
//这是值传递，结构体 p 是 y 的一份副本；

// scanf 修改的是 p.x 和 p.y，跟 y 本身无关；

// 所以原始变量 y 不会被改变。

// void getStruct(struct point p)
// {
//     scanf("%d",&p.x);
//     scanf("%d",&p.y);
//     printf("%d,%d\n",p.x,p.y);
// }

//改进
struct point getStruct(void)
{   
    struct point p;
    scanf("%d",&p.x);
    scanf("%d",&p.y);
    printf("%d,%d\n",p.x,p.y);
    return p;
}


void output(struct point p)
{
    printf("%d,%d\n",p.x,p.y);
}