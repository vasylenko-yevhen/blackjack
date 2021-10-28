#include "config.h"
#include "Card.h"


Card::Card(unsigned short value, std::string name_) {
    minValue = maxValue = value;
    name = name_;
}


Card::Card(unsigned short minValue_, unsigned short maxValue_, std::string name_) {
    minValue = minValue_;
    maxValue = maxValue_;
    name = name_;
}


unsigned short Card::getMaxValue() const {
    return maxValue;
}


unsigned short Card::getActualValue(unsigned short totalScore) {
    return totalScore >= BLACKJACK_SCORE ? minValue : maxValue;
}
