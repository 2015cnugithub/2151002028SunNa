#include<stdio.h>
//�������� 
int isLeapYear(int year);
int GetMonthDays(int year,int month);
int GetWeekDay(int year,int month,int day);
void PrintMonthCalender(int startDay,int day);

main()
{
    int year,month,startDay,days;//�ֱ��ʾ�꣬�£����µ�һ�죬���������� 
    printf("Please input year and month:");
    scanf("%d %d",&year,&month);
    printf("The result is:\n");
    printf("\n\t%d-%d\n",year,month);//��ʽ���ƣ����м��ӡ���� 
    startDay=GetWeekDay(year,month,1);  //��������  
    days=GetMonthDays(year,month);
    PrintMonthCalender(startDay,days); //��ӡ�������� 
    system("pause");    
}

int isLeapYear(int year)
{
    if(year%4==0&&year%100!=0//�ж��Ƿ������� 
       ||year%400==0)
       return 1;
    else
       return 0;    
}

int GetMonthDays(int year,int month)
{
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)//31����·� 
      return 31;
    else if(month==4||month==6||month==9||month==11)//30����·� 
      return 30;
    else //2�� 
    {
       if(isLeapYear(year)==1)//������� 
         return 29;
       else
         return 28;     
    }    
    
}

int GetWeekDay(int year,int month,int day)
{
   int x,days,weekDay,m;//x��ʾ��ǰһ�����������days����������weekday�� ����ֵ��m�������������� 
   x=year-1;//���㵽ǰһ��������� 
   days=x*365+x/400+x/4-x/100+day;
   for(m=1;m<month;m++)
   {
      days=days+GetMonthDays(year,m); //����������               
   } 
   weekDay=days%7;//���������ڼ� 
   return weekDay;//���ظ��������ڼ� 
}

void PrintMonthCalender(int startDay,int days)
{
    int i,j=0,k,count,year,month;//i��ʾ��һ��1ǰ��Ŀո�����j�����ƴ�ӡ�Ŀո�����k��ʾ�죨���ڣ���count��������������ÿ��7�� 
   
   
    printf("Sun. Mon. Tue. Wed. Thu. Fri. Sat. \n");
    i=startDay*5;//��һ�еĿո��� 
    while(j<i)//��ӡ�ո� 
    {
         printf(" ");
         j++;          
    }
    count=startDay;//count����ֵ 
    for(k=1;k<=days;k++)//��ӡ����ÿһ�� 
    {
       count++;
       printf("%-5d",k); //%-5d�Ǹ�ʽ���� 
       if(count%7==0)//ÿ�д�ӡ7�컻�� 
       printf("\n");                  
    }
}
