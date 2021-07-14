#include<bits/stdc++.h>
using namespace std;

///The function, setFirstDayOfYear() returns the day such as SUN,MON,TUE and so on,
///on which a particular year starts
int setFirstDayOfYear(int year)
{
    int FirstDay = (year*365+((year-1)/4) - ((year-1)/100) + ((year - 1)/400)) % 7;
    return FirstDay;
}
int main()
{
    int day, weekStart, month, countspace, year;
    ///The array, months[] contains the 12 months of a year
    char* months[]=
    {
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
    };
    ///The array, DAYSinMONTHS[] contains the number of days in a month
    int DAYSinMONTHS[]= {31,28,31,30,31,30,31,31,30,31,30,31};
    cout<<"Enter a Calender Year : ";
    cin>>year;
    cout<<endl<<endl<<"          Welcome to the Year "<<year<<"!";
    ///Check if the year is a Leap year
    ///if leap year, set February = 29 days
    if ((year%4==0 && year%100!=0) || (year%400==0))
    {
        DAYSinMONTHS[1]=29;
    }
    ///Get the day, the year stars with
    weekStart = setFirstDayOfYear(year);
    //cout<<weekStart;
    for(month=0; month<12; month++)
    {
        cout<<"\n\n\n                   "<< months[month]<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<"   SUN   MON   TUE   WED   THU   FRI   SAT\n";
        ///Positioning the starting place of a day in week in calender
        for (countspace=0; countspace<weekStart; countspace++)
        {
            cout<<"      ";
        }
        ///Positioning the right place of days in month in calender
        for (day=1; day<=DAYSinMONTHS[month]; day++)
        {
            cout<<setw(6)<<day;
            weekStart++;
            ///Condition for starting new week in a month
            if(weekStart>6)
            {
                weekStart=0;
                cout<<endl;
            }
        }
    }

    return 0;
}
