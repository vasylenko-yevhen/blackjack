#include <algorithm>
#include <random>
#include <chrono>
#include "Deck.h"


Deck::Deck(std::vector<Card*>& cards_) {
    cards = cards_;
}


void Deck::reset() {
    currentCard = 0;
    shuffle();
}


Deck::~Deck() {
    reset();
}


Card* Deck::getCard() {
    try {
        return cards.at(currentCard++);
    } catch (std::out_of_range &e){
        return nullptr;
    }
}


void Deck::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}


Deck* Deck::getDeck() {
    std::vector<Card*> cards_ {
        new Card(2, "2"), new Card(2, "2"), new Card(2, "2"), new Card(2, "2"),
        new Card(3, "3"), new Card(3, "3"), new Card(3, "3"), new Card(3, "3"),
        new Card(4, "4"), new Card(4, "4"), new Card(4, "4"), new Card(4, "4"),
        new Card(5, "5"), new Card(5, "5"), new Card(5, "5"), new Card(5, "5"),
        new Card(6, "6"), new Card(6, "6"), new Card(6, "6"), new Card(6, "6"),
        new Card(7, "7"), new Card(7, "7"), new Card(7, "7"), new Card(7, "7"),
        new Card(8, "8"), new Card(8, "8"), new Card(8, "8"), new Card(8, "8"),
        new Card(9, "9"), new Card(9, "9"), new Card(9, "9"), new Card(9, "9"),
        new Card(10, "10"), new Card(10, "10"), new Card(10, "10"), new Card(10, "10"),
        new Card(10, "J"), new Card(10, "J"), new Card(10, "J"), new Card(10, "J"),
        new Card(10, "Q"), new Card(10, "Q"), new Card(10, "Q"), new Card(10, "Q"),
        new Card(10, "K"), new Card(10, "K"), new Card(10, "K"), new Card(10, "K"),
        new Card(1, 11, "A"), new Card(1, 11, "A"), new Card(1, 11, "A"), new Card(1, 11, "A"),
    };
    Deck* deck = new Deck(cards_);
    deck->shuffle();
    return deck;
}