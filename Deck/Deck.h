#ifndef DECK_D
#define DECK_D
#include "Card.h"
#include <string>
using namespace std;

class Deck
{
    private:
        char ranks [13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
        char suites [4] = {'S','H','C','D'};
        int cardCounter = 0;
        Card cards [53];
    public: 
        Deck();
        void refreshDeck();
        Card deal();
        void shuffle();
        int cardsLeft();
        void showDeck();
};
#endifSpade
