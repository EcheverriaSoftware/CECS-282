#ifndef MY_DATE_M
#define MY_DATE_M

#include <iostream>
#include <string>

using namespace std;

class myDate
{
  private:
    int month;
    int day;
    int year;
  public:
    myDate();
    myDate(int, int, int);
    void display();
    void increaseDate(int);
    void decreaseDate(int);
    int daysBetween(myDate);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    string dayName();
    string toString();
};
int Greg2Julian(int, int, int);
void Julian2Greg(int &, int &, int &, int); 
#endif
