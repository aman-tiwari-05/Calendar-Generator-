#include <iostream>
#include<stdlib.h>
using namespace std;
int first_day(int year,int M){   //function for finding first day of(i.e Sunday,Monday etc) month using  Zeller's rule  
    system("Color 3E");  
    int D=year%100;          // M = Month no. ,D = Last two digits of the year, C = The first two digits of year , 
    int C=year/100;          // so for 2021 D=21  C=20 and
    int K=1;                 //according to Zeller calendar For March M=1 ,april M=2 and so on..hence for dec. M=10, Jan M=11, Feb M=12
    int F = K + (13*M - 1)/5 + D + D/4 + C/4 - 2*C;  
    if(F>=0)
     {
       return(F%7);
      }
    else
     {
        return(((F%7)+7)%7);  //this function will return nos 0-6 such tha for 0 first day of month is sunday, fir 1 monday and son on till 6 for Saturday
      }
}
void display_calendar(string month,int Ist_day,int days){
    cout<<"\n------------ "<<month<<" ------------\n\n";
    cout<<"  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
    int weekDay;
    for( weekDay=0;weekDay<Ist_day;weekDay++){
        cout<<"     "; }
    for(int day=1;day<=days;day++){
        if(day<10){
            cout<<"    "<<day;}
        else{
             cout<<"   "<<day;   }

        if(++weekDay>6){
            cout<<"\n";
            weekDay=0;
        }
        
      }


}
int main()   //This is the main function where we take input from user 
{
    int year,n,Ist_day;
    string month;
    string arr[]={"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
    cout<<"Enter year: ";
    cin>>year;
    cout<<"\n Enter first three letters of month (eg. for january enter 'jan') ";
    cin>>month;

    for(int i=0;i<12;i++){     
        if (arr[i]==month){
            n=i;
            break;
        }
    }
    switch(n){    
        case(0):
            Ist_day=first_day(year-1,11);
            display_calendar("January",Ist_day,31);

            break;
        case(1):
           Ist_day=first_day(year-1,12);
           int dates;
           if(year%400==0)
           {
             dates=29;
           }
           else if(year%100==0)
           {
             dates=28;
           }
           else if(year%4==0)
           {
             dates=29;
           }
           else
           {
             dates=28;}

            display_calendar("February",Ist_day,dates);

            break;
        case(2):
            Ist_day=first_day(year,1);
            display_calendar("March",Ist_day,31);
            break;
        case(3):
            Ist_day=first_day(year,2);
            display_calendar("April",Ist_day,30);
            break;
        case(4):
            Ist_day=first_day(year,3);
            display_calendar("May",Ist_day,31);
            break;
        case(5):
            Ist_day=first_day(year,4);
            display_calendar("June",Ist_day,30);
            break;
        case(6):
            Ist_day=first_day(year,5);
            display_calendar("July",Ist_day,31);
            break;
        case(7):
            Ist_day=first_day(year,6);
            display_calendar("August",Ist_day,31);
            break;
        case(8):
            Ist_day=first_day(year,7);
            display_calendar("September",Ist_day,30);
            break;
        case(9):
            Ist_day=first_day(year,8);
            display_calendar("October",Ist_day,31);
            break;
        case(10):
            Ist_day=first_day(year,9);
            display_calendar("Novemver",Ist_day,30);
            break;
        case(11):
            Ist_day=first_day(year,10);
            display_calendar("December",Ist_day,31);
            break;

    }
    return 0;
}
