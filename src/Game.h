#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H


#include "Dealer.h"


class Game {
    Dealer* dealer;
    Player* player;
    Player* casino;
public:
    Game();
    void singleGame();
    void dealPlayerCards();
    void playLoop();
    void reset();
};


int main();


#endif //BLACKJACK_GAME_H
