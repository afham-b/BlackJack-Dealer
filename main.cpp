#include <iostream>
#include "cards.h"
#include "blackjack.h"
#include "dice.h"
#include <algorithm>
#include <cstdlib>
#include <string>
#include <ctime>

int main() {

	Deck d;
	Blackjackcard c1;
	srand(time(0));
	d.shuffle();

	//for (int i=0; i< 20; i++){
	//  c1 = d.deal(); 
	//  cout << c1.str() << " " << c1.score() << endl; 
	//}

	Blackjackhand h;
	for (int i = 0; i < 5; i++) {
		h.add(d.deal());
		cout << h.str() << " " << h.score() << endl;
	}

	return 0;
}