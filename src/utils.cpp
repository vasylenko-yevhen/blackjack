#include <string>
#include <algorithm>
#include "utils.h"


void toLower(std::string& val) {
    std::transform(val.begin(), val.end(), val.begin(), [](unsigned char c){ return std::tolower(c); });
}
