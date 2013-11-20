#ifndef DECK_H_
#define DECK_H_

#include <iostream>
#include "deck.h"

#define INVALID -1
#define STAND 0
#define HIT 1
#define DOUBLE 2
#define SPLIT 3
#define FOLD 4
#define BLACKJACK 5

/*
	The strategy (taken from Wikipedia) used assumes the following parameters:
	- Four to eight decks
	- Dealer stands on a soft 17
	- A double is allowed after a split
	- Only original bets are lost on dealer blackjack
*/

class Strategy {

 public:
 	static int getPlay(int card1, int card2, int dealer);
 	static void printStrategy(int s);

 private:
 	static int pair(int r, int d);
 	static int soft_total(int r, int d);
 	static int hard_total(int r1, int r2, int d);

};



#endif