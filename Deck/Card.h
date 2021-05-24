#ifndef CARD_C
#define CARD_C
#include <string>
using namespace std;


class Card
{
    private:
        char rank;
        char suite;
    public: 
        Card();
        Card(char, char);
        void setCard(char, char);
        int getValue();
        void showCard();
        string getRank();
        string getSuite();
};
#endif
