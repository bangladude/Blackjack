#include "strategy.h"
#include <cstdlib>

/*
Hard totals (excluding pairs)
		Dealer:
Player: 2	3	4	5	6	7	8	9	10	A
17–20	S	S	S	S	S	S	S	S	S	S
16		S	S	S	S	S	H	H	F	F	F
15		S	S	S	S	S	H	H	H	F	H
13–14	S	S	S	S	S	H	H	H	H	H
12		H	H	S	S	S	H	H	H	H	H
11		D	D	D	D	D	D	D	D	D	H
10		D	D	D	D	D	D	D	D	H	H
9		H	D	D	D	D	H	H	H	H	H
5–8		H	H	H	H	H	H	H	H	H	H

Soft totals
			Dealer:
Player:		2	3	4	5	6	7	8	9	10	A
A,8-A,9		S	S	S	S	S	S	S	S	S	S
A,7			S	D	D	D	D	S	S	H	H	H
A,6			H	D	D	D	D	H	H	H	H	H
A,4-A,5		H	H	D	D	D	H	H	H	H	H
A,2-A,3		H	H	H	D	D	H	H	H	H	H

Pairs
	 		Dealer:
Player:		2	3	4	5	6	7	8	9	10	A
A,A			SP	SP	SP	SP	SP	SP	SP	SP	SP	SP
10,10		S	S	S	S	S	S	S	S	S	S
9,9			SP	SP	SP	SP	SP	S	SP	SP	S	S
8,8			SP	SP	SP	SP	SP	SP	SP	SP	SP	SP
7,7			SP	SP	SP	SP	SP	SP	H	H	H	H
6,6			SP	SP	SP	SP	SP	H	H	H	H	H
5,5			D	D	D	D	D	D	D	D	H	H
4,4			H	H	H	SP	SP	H	H	H	H	H
2,2-3,3		SP	SP	SP	SP	SP	SP	H	H	H	H

S = Stand
H = Hit
D = Double
SP = Split
F = Fold
*/

int Strategy::pair(int r, int d) {
	if (r < 1 || r > 13 ||
		d < 1 ||  d > 13) { return INVALID; }

	switch (r) {
		case 1:
			return SPLIT;
		case 2:
			if (d == 1 || d >= 8) { return HIT; }
			else { return SPLIT; }
		case 3:
			if (d == 1 || d >= 8) { return HIT; }
			else { return SPLIT; }
		case 4:
			if (d == 5 || d == 6) { return SPLIT; }
			else { return HIT; }
		case 5:
			if (d == 1 || d == 10) { return HIT; }
			else { return DOUBLE; }
		case 6:
			if (d == 1 || d >= 7) { return HIT; }
			else { return SPLIT; }
		case 7:
			if (d == 0 || d >= 8) { return HIT; }
			else { return SPLIT; }
		case 8:
			return SPLIT;
		case 9:
			if (d == 1 || d == 7 || d == 10) { return STAND; }
			else { return SPLIT; }
		case 10:
			return STAND;
		default:
			return INVALID;
	}
}


int Strategy::soft_total(int r, int d) {
	if (r < 1 || r > 13 ||
		d < 1 ||  d > 13) { return INVALID; }

	switch (r) {
		case 2:
			if (d == 5 || d == 6) { return DOUBLE; }
			else { return HIT; }
		case 3:
			if (d == 5 || d == 6) { return DOUBLE; }
			else { return HIT; }
		case 4:
			if (d >= 4 && d <= 6) { return DOUBLE; }
			else { return HIT; }
		case 5:
			if (d >= 4 && d <= 6) { return DOUBLE; }
			else { return HIT; }
		case 6:
			if (d >= 3 && d <= 6) { return DOUBLE; }
			else { return HIT; }
		case 7:
			if (d == 2 || d == 7 || d == 8) { return STAND; }
			else if (d == 1 || d >= 9) { return HIT; }
			else { return DOUBLE; }
		case 8:
			return STAND;
		case 9:
			return STAND;
		default:
			return INVALID;
	}
}

int Strategy::hard_total(int r1, int r2, int d) {
	int sum = r1 + r2;
	if (sum < 5 || sum > 20) { return INVALID; }

	if (sum >= 5 && sum <= 8) { return HIT; }
	else if (sum == 9) {
		if (d >= 3 && d <= 6) { return DOUBLE; }
		else { return HIT; }
	} else if (sum == 10) {
		if (d == 1 || d == 10) { return HIT; }
		else { return DOUBLE; }
	} else if (sum == 11) {
		if (d == 1) { return HIT; }
		else { return DOUBLE; }
	} else if (sum == 12) {
		if (d >= 4 && d <= 6) { return STAND; }
		else { return HIT; }
	} else if (sum == 13 || sum == 14) {
		if (d == 1 || d >= 7) { return HIT; }
		else { return STAND; }
	} else if (sum == 15) {
		if (d == 10) { return FOLD; }
		else if (d == 1 || d >= 7) { return HIT; }
		else { return STAND; }
	} else if (sum == 16) {
		if (d == 1 || d >= 9) { return FOLD; }
		else if (d >= 7) { return HIT; }
		else { return STAND; }
	} else { return STAND; } // 17-20
}

// card1 and card2 are the player's hand
// dealer is the dealer's faceup card
int Strategy::getPlay(int card1, int card2, int dealer) {
	// Calculate the numeric value; all face cards (11-13) have a value of 10
	int rank1 = card1 % 13;
	if (rank1 == 0 || rank1 > 10) { rank1 = 10; }
	int rank2 = card2 % 13;
	if (rank2 == 0 || rank2 > 10) { rank2 = 10; }
	int d = dealer % 13;
	if (d == 0 || d > 10) { d = 10; }

	if ((rank1 == 1 && rank2 == 10) ||
		(rank1 == 10 && rank2 == 1)) { return BLACKJACK; }

	if (rank1 == rank2) {
		return pair(rank1, d);
	} else if (rank1 == 1) {
		return soft_total(rank2, d);
	} else if (rank2 == 1) {
		return soft_total(rank1, d);
	} else {
		return hard_total(rank1, rank2, d);
	}
}

void Strategy::printStrategy(int s) {
	switch (s) {
		case -1:
			std::cout << "INVALID";
			break;
		case 0:
			std::cout << "STAND";
			break;
		case 1:
			std::cout << "HIT";
			break;
		case 2:
			std::cout << "DOUBLE";
			break;
		case 3:
			std::cout << "SPLIT";
			break;
		case 4:
			std::cout << "FOLD";
			break;
		case 5:
			std::cout << "BLACKJACK";
			break;
		default:
			std::cout << "Not a macro'd strategy";
	}
}
