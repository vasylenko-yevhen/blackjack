#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <iostream>

class Card {
public:
    unsigned short minValue;
    unsigned short maxValue;
    std::string name;

    Card(unsigned short, std::string);
    Card(unsigned short, unsigned short, std::string);

    unsigned short getMaxValue() const;
    unsigned short getActualValue(unsigned short);
};


#endif //BLACKJACK_CARD_H
