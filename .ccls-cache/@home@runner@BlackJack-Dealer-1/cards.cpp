#include "cards.h"
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

char Card::suit() const {
    const char suits[] = { 'H','S','D','C','X' };
    return suits[card_index / 13];
}

char Card::value() const {
    const char values[] =
    { '2','3','4','5','6','7','8','9','T','J','Q','K','A' };
    if (card_index == 52)
        return 'X';
    return values[card_index % 13];
}

std::string Card::str() const {
    std::string s;
    s += value();
    s += suit();
    return s;
}

Deck::Deck() {
    for (int i = 0; i < 52; i++) {
        Card c(i);
        cards[i] = c;
    }
    used_count = 0;
}

void Deck::shuffle() {
    for (int i = 0; i < 52; i++)
        swap(cards[i], cards[rand() % 52]);
    used_count = 0;
}

std::string Hand::str() const {
    std::string s;
    for (int i = 0; i < count; i++) {
        if (i > 0)
            s += "-";
        s += cards[i].str();
    }
    return s;
}