#include "cards.h"
#include "blackjack.h"
#include <algorithm>
#include <cstdlib>
#include <ctime> 
#include <string>

int Blackjackcard::score() const {

    switch (value()) {
    case 'A':
        return 11;
    case 'K':
    case 'Q':
    case 'J':
    case 'T':
        return 10;
    }

    return value() - '0';
}

int Blackjackhand::score() const {
    int sum = 0;
    for (int i = 0; i < size(); i++)
        sum += card(i).score();
    for (int i = 0; i < size(); i++) {
        if (sum > 21 && card(i).value() == 'A') {
            sum -= 10;
        }
    }
    return sum;
}