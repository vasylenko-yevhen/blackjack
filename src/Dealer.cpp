#include "config.h"
#include "Dealer.h"


Dealer::Dealer() {
    deck = Deck::getDeck();
}



bool Dealer::dealCard(Player* player, bool verbose) {
    /*
     * Deals card to player or casino.
     * If card is given to played and his total score exceeds ${BLACKJACK_SCORE}, player lost.
     */
    Card* card = deck->getCard();
    player->addCard(card);
    auto currentMaxScore = player->getMaxScore();
    auto currentScore = player->getActualScore(currentMaxScore);
    if(currentScore > BLACKJACK_SCORE) {
        return false;
    }
    return true;
}


void Dealer::dealCardsToCasino(Player* casino) {
    /*
     * Deal cards to casino hand until it has ${MIN_COMPUTER_TO_TAKE} or more points.
     */
    unsigned short currentScore = casino->getActualScore(casino->getMaxScore());
    while (currentScore < MIN_COMPUTER_TO_TAKE) {
        if(!dealCard(casino, false))
            break;
        currentScore = casino->getActualScore(casino->getMaxScore());
    }
}


void Dealer::reset() {
    deck->reset();
}
