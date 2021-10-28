#include "Player.h"


Player::Player() {
    cards = std::vector<Card*>{};
}


Player::~Player() {
    reset();
}


unsigned short Player::getMaxScore() {
    unsigned short total = 0;
    for(const auto& card: cards) {
        total += card->getMaxValue();
    }
    return total;
}


unsigned short Player::getActualScore(unsigned short maxScore) {
    unsigned short total = 0;
    for(const auto& card: cards) {
        total += card->getActualValue(maxScore);
    }
    return total;
}


void Player::addCard(Card* card) {
    cards.push_back(card);
}


void Player::printCards(bool showAll) {
    unsigned short cardsNumber = showAll ? cards.size() : 1;
    for(unsigned short i=0; i<cardsNumber; i++) {
        std::cout << cards.at(i)->name << " ";
    }
}

void Player::reset() {
    cards.clear();
}