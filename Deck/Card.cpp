#include "Card.h"
#include <iostream>
using namespace std;

Card :: Card()
{
    rank = ' ';
    suite = ' ';
}
Card :: Card(char r, char s)
{
    rank = r;
    suite = s;
}
void Card :: setCard(char r, char s)
{
    rank = r;
    suite = s;
}
int Card :: getValue()
{
    if(rank == 'A'){
        return 1; 
    } else if(rank == '2'){
        return 2;
    } else if(rank == '3'){
        return 3;
    } else if(rank == '4'){
        return 4;
    } else if(rank == '5'){
        return 5;
    } else if(rank == '6'){
        return 6;
    } else if(rank == '7'){
        return 7;
    }else if(rank == '8'){
        return 8;
    }
    else if(rank == '9'){
        return 9;
    }else{
        return 10;
    }
}
void Card :: showCard()
{
    cout << rank << suite;
}
string Card :: getRank()
{
  std:: string r(1, rank);
  return r;
}
string Card :: getSuite()
{
  std:: string s(1, suite);
  return s;
}
