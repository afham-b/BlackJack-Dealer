#pragma once 

#include "cards.h"
#include <string> 
using namespace std;

class Blackjackcard : public Card {
public:
    int score() const;
    Blackjackcard() : Card() { }    //default constructor from card class. 
    Blackjackcard(const Card& c) : Card(c) { } //specific implentation.  
};

class Blackjackhand : public Hand {
public:
    Blackjackhand() : Hand() { }
    Blackjackcard card(int index) const { return Hand::card(index); }
    //overides card funtion in public of Hand Class
    Blackjackhand(const Hand& h) : Hand(h) { }
    int score() const;
};
