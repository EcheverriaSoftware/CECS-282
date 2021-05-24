//Miguel Echeverria
//Class (CECS 282-05)
//Programming Assignment 1
// Due Date (2/09/2021)
// 
/*I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program.*/
 #include "Card.h"
 #include "Deck.h"
 #include <iostream>
 #include <string>
 using namespace std;

 void printMenu()
 {
   cout << "Welcome to Solitare Prime!" << endl;
   cout << "1) New Deck" << endl;
   cout << "2) Disply Deck" << endl;
   cout << "3) Shuffle Deck" << endl;
   cout << "4) Play Solitare Prime" << endl;
   cout << "5) Exit" << endl;
 }
 int getInput()
 {
   int num;
   cout << "Enter your option: " << endl;
   cin >> num;
   while((num != 1) && (num != 2) && (num != 3) && (num != 4) && (num != 5))
   {
    cout << "Enter a valid option: " << endl;
    cin >> num;
   }
   return num;
 }
 int checkInput()
 {
   int userInput;
   while((userInput != 1) && (userInput != 2) && (userInput != 3) && (userInput != 4) && (userInput != 5))
    {
      userInput = getInput();
    }
    return userInput;
 }
 bool isPrime(int num)
 {
   if(num <= 1)
   {
     return false;
   }
   for(int i = 2; i < num; i++)
   {
     if((num % i) == 0)
     {
       return false;
     }
   }
   return true;
 }
 int main()
 {
    int primePiles = 0;
    Deck d;
    Card c;
    string output;
    bool win = false;
    int sum = 0;
    int userInput = 0;
    while(userInput != 5)
    {
      printMenu();
      int userInput = getInput();
      if(userInput == 1)
      {
        d.refreshDeck();
        cout << "New deck created" << endl;
        cout << endl;
      }
      else if(userInput == 2)
      {
        if(d.cardsLeft() == 0){
          cout << "You need to organize a new deck first." << endl;
          continue;
        }
        cout << "Here are all the cards in the deck" << endl;
        d.showDeck();
        cout << endl;
      }
      else if(userInput == 3)
      {
        if(d.cardsLeft() == 0){
          cout << "You need to organize a new deck first." << endl;
          continue;
        }
        d.shuffle();
        cout << "The deck has been shuffled" << endl;
        cout << endl;
      }
      else if(userInput == 4)
      {
        if(d.cardsLeft() == 0){
          cout << "You need to organize a new deck first." << endl;
          continue;
        }
        cout << "Playing Solitare Prime!!" << endl;
        while(d.cardsLeft() != 0)
        {
          c = d.deal();
          sum += c.getValue();
          output = output + c.getRank() + c.getSuite() + " ";
          if(isPrime(sum) || d.cardsLeft() == 0)
          {
            if(isPrime(sum) && d.cardsLeft() == 0)
            {
              cout << output << " " << "Prime: " << sum << endl;
              win = true;
              break;
            }
            cout << output << " " << "Prime: " << sum << endl;
            sum = 0;
            output = "";
            primePiles++;
          }
        }
        if(win){
          cout << "Winner in " << primePiles << " piles" << endl;
          break;
        }
        cout << "Loser" << endl;
        cout << endl;
        primePiles = 0;
      }
      else
      {
        cout << "Thank you for playing" << endl;
        break;
      }
    }

 }
