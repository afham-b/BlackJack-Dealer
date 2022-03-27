#pragma once 

#include <string> 
using namespace std;

class Card {
	friend class Deck;
private:
	int card_index;
	Card(int index) { card_index = index; }
public:
	Card() { card_index = 52; }
	char suit() const;
	char value() const;
	string str() const;
};

class Deck {
private:
	Card cards[52];
	int used_count;
public:
	Deck();
	Card deal() { return cards[used_count++]; }
	void shuffle();
	int size() const { return 52 - used_count; }
};

class Hand {
private:
	Card cards[52];
	int count; // Number of elements in cards that is occupied
public:
	Hand() { count = 0; }
	void add(const Card& c) { cards[count++] = c; }
	Card card(int index) const { return cards[index]; }
	void clear() { count = 0; }
	void remove(int index) { cards[index] = cards[--count]; }
	int size() const { return count; }
	string str() const;
};
