#ifndef UP_DATE_U
#define UP_DATE_U

#include <iostream>
#include <string>

using namespace std;

class upDate
{
  private:
    int * ptr;
    static int upDateCounter;
  public:
    upDate();
    upDate(int, int, int);
    upDate(int);
    upDate(const upDate &);
    ~upDate();
    upDate operator=(const upDate &);
    upDate operator+=(int);
    upDate operator+(int);
    upDate operator++(int);
    upDate operator-=(int);
    upDate operator-(int);
    upDate operator--(int);
    void setDate(int, int, int);
    int getMonth();
    int getDay();
    int getYear();
    int julian();
    static int GetDateCount();
    string getMonthName();
    friend upDate operator+(int, const upDate &);
    friend upDate & operator++(upDate &);
    friend upDate & operator--(upDate &);
    friend int operator-(const upDate & u, const upDate & u2);
    friend bool operator==(const upDate & u, const upDate & u2);
    friend bool operator>(const upDate & u, const upDate & u2);
    friend bool operator<(const upDate & u, const upDate & u2);
    friend ostream& operator<<(ostream& os, const upDate &u);
  
};
int Greg2Julian(int, int, int);
void Julian2Greg(int &, int &, int &, int);
#endif
