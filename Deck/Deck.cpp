#include "Deck.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using namespace std;

Deck :: Deck()
{
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 13; j++)
    {
      cards[cardCounter] = Card(ranks[j], suites[i]);
      cardCounter++;
    }
  }
  cardCounter++;
}
void Deck :: refreshDeck()
{
  cardCounter = 0;
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 13; j++)
    {
      cards[cardCounter].setCard(ranks[j], suites[i]);
      cardCounter++;
    }
  }
}
Card Deck :: deal()
{
  Card draw = cards[--cardCounter];
  return draw;
}

void Deck :: shuffle()
{
  srand(time(0));
  for(int i = 0; i < 104; i++)
  {
    int x = rand() % (cardCounter);
    int y = rand() % (cardCounter);
    Card temp = cards[x];
    cards[x] = cards[y];
    cards[y] = temp;
     
  }
}
int Deck :: cardsLeft()
{
  return cardCounter;
}
void Deck :: showDeck()
{
  int counter = 0;
  for(int i = 0; i < cardCounter; i++)
  {
    cards[i].showCard();
    cout << "\t";
    counter++;
    if(counter == 13) 
    {
      cout << endl;
      counter = 0;
    }
  }
}
