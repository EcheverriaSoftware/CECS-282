#include "myDate.h"
#include <string>
#include <iostream> 

using namespace std; 

myDate :: myDate()
{
  month = 5;
  day = 11;
  year = 1959;
}
myDate :: myDate(int m, int d, int y)
{
  bool isValidDate = true; 
  if(d < 1 || d > 31 || m < 1 || m > 12)
  {
    isValidDate = false;
  }
  if(d > 28)
  {
    if(m == 4 || m == 6 || m == 9 || m == 11)
    {
      if(d > 30)
      {
        isValidDate = false;
      }
    }
    if(m == 2 && d == 29)
    {
      int leapyearJD = Greg2Julian(12, 31, y);
      int startOfYearJD = Greg2Julian(1, 1, y);
      if((leapyearJD - startOfYearJD) + 1 == 366)
      {
        isValidDate = true;
      } 
      else
      {
        isValidDate = false;
      }
    }
  }
  if(isValidDate)
  {
    month = m;
    day = d;
    year = y;
  }
  else
  {
    month = 5;
    day = 11;
    year = 1959;
  }
}
void Julian2Greg(int & month, int & day, int & year, int JD)
{
  int I,J,K;
  int L= JD+68569;                                                     
  int N= 4*L/146097;                                                     
  L= L-(146097*N+3)/4;                                               
  I= 4000*(L+1)/1461001;                                           
  L= L-1461*I/4+31;                                                  
  J= 80*L/2447;                                                      
  K= L-2447*J/80;                                                    
  L= J/11;                                                           
  J= J+2-12*L;                                                       
  I= 100*(N-49)+I+L;                                                           
  year= I;                                                           
  month= J;                                                          
  day= K;
}
int Greg2Julian(int month, int day, int year)
{
  int JD = day-32075+1461*(year+4800+(month-14)/12)/4+367*(month-2-(month-14)/12*12)      
         /12-3*((year+4900+(month-14)/12)/100)/4;  
  return JD;
}
void myDate :: display()
{
   string monthNames [12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
   cout << monthNames[month - 1] << " " << day << ", " << year; 

}
void myDate :: increaseDate(int N)
{
  int JD = Greg2Julian(month, day, year);
  JD += N; 
  Julian2Greg(month, day, year, JD);
}
void myDate :: decreaseDate(int N)
{
  int JD = Greg2Julian(month, day, year);
  JD -= N; 
  Julian2Greg(month, day, year, JD);
}
int myDate :: daysBetween(myDate D)
{
  int JD1 = Greg2Julian(month, day, year);
  int JD2 = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());
  if(JD1 < JD2)
  {
    return JD2 - JD1;
  }
  return JD2 - JD1; 
}
int myDate :: getMonth()
{
  return month;
}
int myDate :: getDay()
{
  return day;
}
int myDate :: getYear()
{
  return year;
}
int myDate :: dayOfYear()
{
  int JD1 = Greg2Julian(month, day, year);
  int JD2 = Greg2Julian(1, 1, year);
  return (JD1 - JD2) + 1; 
}
string myDate :: dayName()
{
  string daysOfTheWeek [7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  int JD = Greg2Julian(month, day, year);
  return daysOfTheWeek[JD % 7];
}
string myDate :: toString()
{
  string monthNames [12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  string m = monthNames[month - 1];
  string d = to_string(day);
  string y = to_string(year);
  string output = m + " " + d + "," + y;
  return output;
}
