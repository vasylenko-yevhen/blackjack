#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include <vector>
#include "Card.h"


class Player {
    std::vector<Card*> cards;
public:
    Player();
    ~Player();
    unsigned short getMaxScore();
    unsigned short getActualScore(unsigned short);
    void addCard(Card*);
    void printCards(bool);
    void reset();
};

#endif  //BLACKJACK_PLAYER_H