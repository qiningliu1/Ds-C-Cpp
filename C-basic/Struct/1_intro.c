#include<stdio.h>

int main(int argc,char const *argv[])
{
    struct date{
        int month;
        int day;
        int year;
    };//声明在这里，最后要加上分号哦，这是在函数内部声明的，通常放在函数外面
    
    struct date today;//在这里我们定义了一个变量是today，类型是struct date的
    
    today.month = 07;
    today.day = 31;
    today.year = 2014;
    
    printf("Today's date is %i-%i-%i.\n",today.year,today.month,today.day);
    
    return 0;
}

//声明结构类型跟定义结构变量是两件事情哦