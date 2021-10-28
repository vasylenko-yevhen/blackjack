#ifndef BLACKJACK_DEALER_H
#define BLACKJACK_DEALER_H

#include "Deck.h"
#include "Player.h"


class Dealer {
    Deck* deck;
public:
    Dealer();
    bool dealCard(Player*, bool=false);
    void dealCardsToCasino(Player*);
    void reset();
};


#endif //BLACKJACK_DEALER_H
