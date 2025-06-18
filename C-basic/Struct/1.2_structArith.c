#include<stdio.h>

struct date{
    int month;
    int day;
    int year;
};

int main(int argc,char const *argv[])
{
    struct date today;
    
    today = (struct date){07,31,2014};
    
    struct date day;//如果不初始化，那末就是随机脏数据
    
    day = today;//day 成为了 today 的值复制（深拷贝)
    day.year = 2015;//可以看出todayu不受影响


    struct date *pDate = &today;  //指向地址
    pDate->year = 2016;//使用指针
    


    printf("Today's date is %i-%i-%i.\n",today.year,today.month,today.day);
    printf("The day's date is %i-%i-%i.\n",day.year,day.month,day.day);
    
    printf("address of today is %p\n",pDate);
    printf("address of day is %p\n",&day);//注意地址不同与today但是挨着一个sizeof(struct)
    return 0;
}