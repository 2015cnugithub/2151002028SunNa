#include<stdio.h>
//函数声明 
int isLeapYear(int year);
int GetMonthDays(int year,int month);
int GetWeekDay(int year,int month,int day);
void PrintMonthCalender(int startDay,int day);

main()
{
    int year,month,startDay,days;//分别表示年，月，该月第一天，该月总天数 
    printf("Please input year and month:");
    scanf("%d %d",&year,&month);
    printf("The result is:\n");
    printf("\n\t%d-%d\n",year,month);//格式控制，在中间打印年月 
    startDay=GetWeekDay(year,month,1);  //函数调用  
    days=GetMonthDays(year,month);
    PrintMonthCalender(startDay,days); //打印该月日历 
    system("pause");    
}

int isLeapYear(int year)
{
    if(year%4==0&&year%100!=0//判断是否是闰年 
       ||year%400==0)
       return 1;
    else
       return 0;    
}

int GetMonthDays(int year,int month)
{
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)//31天的月份 
      return 31;
    else if(month==4||month==6||month==9||month==11)//30天的月份 
      return 30;
    else //2月 
    {
       if(isLeapYear(year)==1)//闰年与否 
         return 29;
       else
         return 28;     
    }    
    
}

int GetWeekDay(int year,int month,int day)
{
   int x,days,weekDay,m;//x表示到前一年的整年数，days是总天数，weekday是 返回值，m用来计算总天数 
   x=year-1;//计算到前一年的整年数 
   days=x*365+x/400+x/4-x/100+day;
   for(m=1;m<month;m++)
   {
      days=days+GetMonthDays(year,m); //计算总天数               
   } 
   weekDay=days%7;//计算是星期几 
   return weekDay;//返回该天是星期几 
}

void PrintMonthCalender(int startDay,int days)
{
    int i,j=0,k,count,year,month;//i表示第一行1前面的空格数，j用来计打印的空格数，k表示天（日期），count用来计数，控制每行7天 
   
   
    printf("Sun. Mon. Tue. Wed. Thu. Fri. Sat. \n");
    i=startDay*5;//第一行的空格数 
    while(j<i)//打印空格 
    {
         printf(" ");
         j++;          
    }
    count=startDay;//count赋初值 
    for(k=1;k<=days;k++)//打印该月每一天 
    {
       count++;
       printf("%-5d",k); //%-5d是格式控制 
       if(count%7==0)//每行打印7天换行 
       printf("\n");                  
    }
}
