#include "upDate.h"
#include <iostream>

using namespace std;
int upDate :: upDateCounter = 0;
//gets num of upDate objects
int upDate :: GetDateCount()
{
  return upDateCounter;
}
//default constructor
upDate :: upDate()
{
  ptr = new int [3];
  ptr[0] = 5;
  ptr[1] = 11;
  ptr[2] = 1959;
  upDateCounter++;
}
//overloaded constructor
upDate :: upDate(int m, int d, int y)
{
  ptr = new int [3];
  upDateCounter++;
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
    ptr[0] = m;
    ptr[1] = d;
    ptr[2] = y;
  }
  else
  {
    ptr[0] = 5;
    ptr[1] = 11;
    ptr[2] = 1959;
  }
}
//overloaded instructor using julian date
upDate :: upDate(int j)
{
  upDateCounter++;
  ptr = new int [3];
  int I,J,K;
  int L= j + 68569;                                                      
  int N= 4*L/146097;                                                     
  L= L-(146097*N+3)/4;                                               
  I= 4000*(L+1)/1461001;                                             
  L= L-1461*I/4+31;                                                  
  J= 80*L/2447;                                                      
  K= L-2447*J/80;                                                    
  L= J/11;                                                           
  J= J+2-12*L;                                                       
  I= 100*(N-49)+I+L;                                                    
  ptr[2] = I;                                                           
  ptr[0] = J;                                                          
  ptr[1] = K;
  /*year = I;                                                           
  month = J;                                                          
  day = K;
  */
}
//overloaded constructor using an upDate object
upDate :: upDate(const upDate & uD)
{
  ptr = new int [3];
  ptr[0] = uD.ptr[0];
  ptr[1] = uD.ptr[1];
  ptr[2] = uD.ptr[2];
  upDateCounter++;
}
//sets date of an upDate object
void upDate :: setDate(int m, int d, int y)
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
    ptr[0] = m;
    ptr[1] = d;
    ptr[2] = y;
  }
  else
  {
    ptr[0] = 5;
    ptr[1] = 11;
    ptr[2] = 1959;
  }
}
//destructor
upDate :: ~upDate()
{
  delete ptr;
  upDateCounter--;
}
//overloaded assign operator
upDate upDate :: operator=(const upDate & u)
{
  ptr = new int[3];
  ptr[0] = u.ptr[0];
  ptr[1] = u.ptr[1];
  ptr[2] = u.ptr[2];
  return *this;
}
//overloaded addition operator
upDate upDate :: operator+(int n)
{
  int JD = Greg2Julian(ptr[0], ptr[1], ptr[2]);
  JD += n;
  upDate temp;
  Julian2Greg(temp.ptr[0], temp.ptr[1], temp.ptr[2], JD);
  return temp; 
}
//overloaded += operator
upDate upDate :: operator+=(int n)
{
  int JD = Greg2Julian(ptr[0], ptr[1], ptr[2]);
  JD += n;
  Julian2Greg(ptr[0], ptr[1], ptr[2], JD);
  return *this; 
}
//overloaded post style increment operator
upDate upDate :: operator++(int)
{
  upDate temp = *this;
  int JD = Greg2Julian(ptr[0], ptr[1], ptr[2]);
  JD += 1;
  Julian2Greg(ptr[0], ptr[1], ptr[2], JD);
  return temp;
}
//overloaded subtraction operator
upDate upDate :: operator-(int n)
{
  int JD = Greg2Julian(ptr[0], ptr[1], ptr[2]);
  JD -= n;
  upDate u;
  Julian2Greg(u.ptr[0], u.ptr[1], u.ptr[2], JD);
  return u; 
}
//overloaded -= operator
upDate upDate :: operator-=(int n)
{
  int JD = Greg2Julian(ptr[0], ptr[1], ptr[2]);
  JD -= n;
  Julian2Greg(ptr[0], ptr[1], ptr[2], JD);
  return *this; 
}
//overloaded post style decerement operator
upDate upDate :: operator--(int)
{
  upDate temp = *this;
  int JD = Greg2Julian(ptr[0], ptr[1], ptr[2]);
  JD -= 1;
  Julian2Greg(ptr[0], ptr[1], ptr[2], JD);
  return temp;
}
//gets month
int upDate :: getMonth()
{
  return ptr[0];
}
//gets day
int upDate :: getDay()
{
  return ptr[1];
}
//gets year
int upDate :: getYear()
{
  return ptr[2];
}
//gets julian date of upDate object
int upDate :: julian()
{
  int JD = Greg2Julian(ptr[0], ptr[1], ptr[2]);
  return JD; 
}
//gets month name
string upDate :: getMonthName()
{
  string monthNames [12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  return monthNames[ptr[0] - 1];
}
void Julian2Greg(int &month, int &day, int &year, int JD)
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
  year = I;                                                           
  month = J;                                                          
  day = K;
}
int Greg2Julian(int month, int day, int year)
{
  int JD = day-32075+1461*(year+4800+(month-14)/12)/4+367*(month-2-(month-14)/12*12)      
         /12-3*((year+4900+(month-14)/12)/100)/4;  
  return JD;
}

upDate operator+(int n, const upDate & u)
{
  int JD = Greg2Julian(u.ptr[0], u.ptr[1], u.ptr[2]);
  JD += n;
  upDate u2;
  Julian2Greg(u2.ptr[0], u2.ptr[1], u2.ptr[2], JD);
  return u2; 
}

upDate & operator++(upDate & u)
{
  int JD = Greg2Julian(u.ptr[0], u.ptr[1], u.ptr[2]);
  JD += 1;
  Julian2Greg(u.ptr[0], u.ptr[1], u.ptr[2], JD);
  return u;
}
upDate & operator--(upDate & u)
{
  int JD = Greg2Julian(u.ptr[0], u.ptr[1], u.ptr[2]);
  JD -= 1;
  Julian2Greg(u.ptr[0], u.ptr[1], u.ptr[2], JD);
  return u;
}
int operator-(const upDate & u, const upDate & u2)
{
  int JD1 = Greg2Julian(u.ptr[0], u.ptr[1], u.ptr[2]); 
  int JD2 = Greg2Julian(u2.ptr[0], u2.ptr[1], u2.ptr[2]);
  int difference = JD1 - JD2;
  return difference; 
}
bool operator==(const upDate & u, const upDate & u2)
{
  if(u.ptr[0] == u2.ptr[0] && u.ptr[1] == u2.ptr[1] && u.ptr[2] == u2.ptr[2])
  {
    return true;
  }
  else
  {
    return false;
  }
  
}
bool operator>(const upDate & u, const upDate & u2)
{
  int JD1 = Greg2Julian(u.ptr[0], u.ptr[1], u.ptr[2]); 
  int JD2 = Greg2Julian(u2.ptr[0], u2.ptr[1], u2.ptr[2]);
  if(JD1 > JD2)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator<(const upDate & u, const upDate & u2)
{
  int JD1 = Greg2Julian(u.ptr[0], u.ptr[1], u.ptr[2]); 
  int JD2 = Greg2Julian(u2.ptr[0], u2.ptr[1], u2.ptr[2]);
  if(JD1 < JD2)
  {
    return true;
  }
  else
  {
    return false;
  }
}
ostream& operator<<(ostream& os, const upDate &u)
{
  os << "" << u.ptr[0] << "/" << u.ptr[1] << "/" << u.ptr[2];
  return os;
}
