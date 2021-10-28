#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>
#include "Card.h"


class Deck {
    unsigned short currentCard=0;
    std::vector<Card*> cards;

    Deck(std::vector<Card*>&);
    void shuffle();
public:
    Card* getCard();
    void reset();
    ~Deck();

    static Deck* getDeck();
};


#endif //BLACKJACK_DECK_H
