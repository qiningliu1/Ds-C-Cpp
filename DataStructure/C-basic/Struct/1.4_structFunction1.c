#include<stdio.h>

struct point {
    int x;
    int y;
};

// C语言函数声明（原型）中：
// 参数名是 可选的，只要给出参数的类型即可。
struct point* getStruct(struct point*);
void output(struct point);
void print(const struct point *p);

int main(int argc,char const *argv[])
{
    struct point y = {0,0};
    getStruct(&y);
    output(y);
    output(*getStruct(&y));//这里需要加*，因为getStruct返回的是指针。需要加*取值
    print(getStruct(&y));
    *getStruct(&y) = (struct point){1,2};//赋值号的左边作为左值
}

struct point*getStruct(struct point*p)
{
    scanf("%d",&p->x);
    scanf("%d",&p->y);
    printf("%d,%d",p->x,p->y);
    return p;
}

void output(struct point p)
{
    printf("%d,%d",p.x,p.y);
}

//这个const是告诉编译器，这个函数不能修改p的值，即不能修改结构体的值
void print(const struct point *p)
{
    printf("%d,%d",p->x,p->y);
}