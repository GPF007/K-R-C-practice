#include <stdio.h>

static char daytab[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year,int month,int day);
void month_day(int year,int yearday,int *pmonth,int *pday);
char *month_name(int n);

int main(int argc, char const *argv[])
{
    int m,d;
    month_day(1988,60,&m,&d);
    printf("month:%d day:%d\n",m,d);
    printf("month_name(8) = %s\n",month_name(8));
    return 0;
}



int day_of_year(int year,int month,int day){
    int i,leap;
    leap = year%4==0 && year%100!=0 ||year%400==0;
    for(i=1;i<month;i++)
        day+=daytab[leap][i];
    return day;
}

void month_day(int year,int yearday,int *pmonth,int *pday){
    int i,leap;

    leap = year%4==0 && year%100!=0 || year%400==0;
    for(i=1;yearday>daytab[leap][i];i++)
        yearday-=daytab[leap][i];
    *pmonth=i;
    *pday=yearday;

}

char *month_name(int n){
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"};
    return name[n];
}
