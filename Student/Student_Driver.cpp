#include <iostream>
#include <string.h> 
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myDate.h"
using namespace std;

struct Student
{
  char name [40];
  int studentID;
  char grade;
  myDate birthday;
  string homeTown;
};
void menu()
{
  cout << "1). Display list sorted by Name" << endl;
  cout << "2). Display list sorted by Student ID" << endl;
  cout << "3). Display list sorted by Grade" << endl;
  cout << "4). Display list sorted by Birthday" << endl;
  cout << "5). Display list sorted by Home Town" << endl; 
  cout << "6). Exit" << endl; 
}
void display(Student ** sptr)
{
  cout.setf(ios :: left);
  cout.width(20); 
  cout << "Name";
  cout.width(15); 
  cout << "StudentID"; 
  cout.width(10);
  cout << "Grade"; 
  cout.width(25);
  cout << "Birthday"; 
  cout.width(10);
  cout << "HomeTown"; 
  cout << endl;
  cout << endl;
  for(int i = 0; i < 10; i++)
  {
    cout.width(20); 
    cout << (*(*(sptr + i))).name; 
    cout.width(15); 
    cout << (*(*(sptr + i))).studentID; 
    cout.width(10);
    cout << (*(*(sptr + i))).grade; 
    cout.width(25);
    cout << (*(*(sptr + i))).birthday.toString(); 
    cout.width(10);
    cout << (*(*(sptr + i))).homeTown; 
    cout << endl;
  }
}
void populate(Student * sptr [])
{
  srand(time(0));
  for(int i = 0; i < 10; i++)
  {
    int studentID = rand() % (9999 - 9000 + 1) + 9000;
    int julianDate = rand() % (2453736 - 2449719 + 1) + 2449719;
    int month = 0;
    int day = 0;
    int year = 0;
    Julian2Greg(month, day, year, julianDate);
    myDate d(month, day, year);
    if(i == 0)
    {
      sptr[i] = new Student{.name = "Miguel Echeverria", .studentID = studentID, .grade = 'A', .birthday = d, .homeTown = "Lynwood"};
    }
    else if(i == 1)
    {
      sptr[i] = new Student{.name = "Angel Echeverria", .studentID = studentID, .grade = 'B', .birthday = d, .homeTown = "Lynwood"};
    }
    else if(i == 2)
    {
      sptr[i] = new Student{.name = "Allyson Ammerlaan", .studentID = studentID, .grade = 'C', .birthday = d, .homeTown = "Chandler"};
    }
    else if(i == 3)
    {
      sptr[i] = new Student{.name = "Allison Austin", .studentID = studentID, .grade = 'A', .birthday = d, .homeTown = "Berkeley"};
    }
    else if(i == 4)
    {
      sptr[i] = new Student{.name = "Timmy Romero", .studentID = studentID, .grade = 'B', .birthday = d, .homeTown = "Downey"};
    }
    else if(i == 5)
    {
      sptr[i] = new Student{.name = "Vivian Dinh", .studentID = studentID, .grade = 'B', .birthday = d, .homeTown = "San Francisco"};
    }
    else if(i == 6)
    {
      sptr[i] = new Student{.name = "Andrew Merino", .studentID = studentID, .grade = 'F', .birthday = d, .homeTown = "Downey"};
    }
    else if(i == 7)
    {
      sptr[i] = new Student{.name = "Michael Moon", .studentID = studentID, .grade = 'A', .birthday = d, .homeTown = "Downey"};
    }
    else if(i == 8)
    {
      sptr[i] = new Student{.name = "Emily Marin", .studentID = studentID, .grade = 'B', .birthday = d, .homeTown = "Long Beach"};
    }
    else
    {
      sptr[i] = new Student{.name = "Markie Davis", .studentID = studentID, .grade = 'A', .birthday = d, .homeTown = "Long Beach"};
    }
  }
}
void sortByName(Student ** sptr)
{
  cout <<"Now sorted by names." << endl;
  bool isSorted = false;
  int unsortedLength = 9;
  while(!isSorted)
  {
    isSorted = true;
    for(int i = 0; i < unsortedLength; i++)
    {
      Student ** s1 = sptr + i;
      Student ** s2 = sptr + i + 1;
      int res = strcmp((*s1)->name, (*s2)->name); 
      if(res > 0)
      {
        Student * tempptr = *s1;     //swap the pointers
        *s1 = *s2;
        *s2 = tempptr;
        isSorted = false;
      }
    }
  }
}
void sortByGrade(Student ** sptr)
{
  cout <<"Now sorted by grades." << endl;
  bool isSorted = false;
  int unsortedLength = 9;
  while(!isSorted)
  {
    isSorted = true;
    for(int i = 0; i < unsortedLength; i++)
    {
      Student ** s1 = sptr + i;
      Student ** s2 = sptr + i + 1;
      int res = strcmp((*s1)->name, (*s2)->name); 
      if((*s1)->grade == (*s2)->grade)
      {
        if(res > 0)
        {
          Student * tempptr = *s1;     //swap the pointers
          *s1 = *s2;
          *s2 = tempptr;
          isSorted = false;
        }
      } 
      else if((*s1)->grade > (*s2)->grade)
      {
        Student * tempptr = *s1;     //swap the pointers
        *s1 = *s2;
        *s2 = tempptr;
        isSorted = false;
      }
    }
  }
}
void sortByID(Student ** sptr)
{
  cout <<"Now sorted by ID." << endl;
  bool isSorted = false;
  int unsortedLength = 9;
  while(!isSorted)
  {
    isSorted = true;
    for(int i = 0; i < unsortedLength; i++)
    {
      Student ** s1 = sptr + i;
      Student ** s2 = sptr + i + 1;
      if((*s1)->studentID > (*s2)->studentID)
      {
        Student * tempptr = *s1;     //swap the pointers
        *s1 = *s2;
        *s2 = tempptr;
        isSorted = false;
      }
    }
  }
}
void sortByBirthday(Student ** sptr)
{
  cout <<"Now sorted by birthdays." << endl;
  bool isSorted = false;
  int unsortedLength = 9;
  while(!isSorted)
  {
    isSorted = true;
    for(int i = 0; i < unsortedLength; i++)
    {
      Student ** s1 = sptr + i;
      int JD1 = Greg2Julian((*(*s1)).birthday.getMonth(), (*(*s1)).birthday.getDay(), (*(*s1)).birthday.getYear());
      Student ** s2 = sptr + i + 1;
      int JD2 = Greg2Julian((*(*s2)).birthday.getMonth(), (*(*s2)).birthday.getDay(), (*(*s2)).birthday.getYear());
      if(JD1 > JD2)
      {
        Student * tempptr = *s1;     //swap the pointers
        *s1 = *s2;
        *s2 = tempptr;
        isSorted = false;
      }
    }
  }
}
void sortByTown(Student ** sptr)
{
  cout <<"Now sorted by towns." << endl;
  bool isSorted = false;
  int unsortedLength = 9;
  while(!isSorted)
  {
    isSorted = true;
    for(int i = 0; i < unsortedLength; i++)
    {
      Student ** s1 = sptr + i;
      Student ** s2 = sptr + i + 1;
      int res = strcmp((*s1)->name, (*s2)->name); 
      if((*s1)->homeTown == (*s2)->homeTown)
      {
        if(res > 0)
        {
          Student * tempptr = *s1;     //swap the pointers
          *s1 = *s2;
          *s2 = tempptr;
          isSorted = false;
        }
      } 
      else if((*s1)->homeTown > (*s2)->homeTown)
      {
        Student * tempptr = *s1;     //swap the pointers
        *s1 = *s2;
        *s2 = tempptr;
        isSorted = false;
      }
    }
  }
}
int main() 
{
  Student * sptrArray[10];	// declare an array of Student pointers
	Student ** sptr = sptrArray; // Student pointer pointer
	populate(sptr);	// pass the pointer to the populate function
  int userInput;
  while(userInput != 6 )
  {
    menu();
    cout << "Enter an option" << endl;
    cin >> userInput;
    cout << endl;
    while(userInput < 1 || userInput > 6)
    {
      cout << "Invalid option, enter again" << endl;
      cin >> userInput;
      cout << endl;
    }
    if(userInput == 1)
    {
      sortByName(sptr);
      display(sptr);
      cout << endl;
    }
    else if(userInput == 2)
    {
      sortByID(sptr);
      display(sptr);
      cout << endl;
    }
    else if(userInput == 3)
    {
      sortByGrade(sptr);
      display(sptr);
      cout << endl;
    }
    else if(userInput == 4)
    {
      sortByBirthday(sptr);
      display(sptr);
      cout << endl;
    }
    else if(userInput == 5)
    {
      sortByTown(sptr);
      display(sptr);
      cout << endl;
    }
    else if(userInput == 6)
    {
      cout << "Thank for using my program, have a nice day" << endl;
      break;
    }

  }
	return 0;
}  
