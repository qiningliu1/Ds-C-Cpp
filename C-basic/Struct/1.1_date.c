#include <stdio.h>
struct date
{
    /* data */
    int month;
    int day;
    int year;
};

int main(int argc, char *argv[]){

    struct date today = {07,31,2014};
    struct date thisMonth = {.month = 7, .year = 2014};

    printf("%d/%d/%d\n",today.month,today.day,today.year);
    printf("%d/%d/%d\n",thisMonth.month,thisMonth.day,thisMonth.year);//没给的值填0

    return 0;

}
