#include <algorithm>
#include "deck.h"

Deck::Deck() {
  deck = 0;
  counter = 0;
  size = 0;
}

/* Cards are defined by a suit and rank, both of which are incorporated into a
 * single int value. Ace through king for clubs are 1-13, ace through king of
 * diamonds are 14 - 26, ace through king of hearts are 27 - 39, and ace
 * through king of spades are 40 - 52.
 */
void Deck::populateDeck(int* deck) {
  for (int i = 0; i < size; i++) {
    for (int suit = 0; suit < 4; suit++) {
      for (int rank = 1; rank <= 13; rank++) {
  	deck[i * 52 + suit * 13 + rank - 1] = suit * 13 + rank;
      }
    }
  }
  std::random_shuffle(deck, deck + size * 52);
}

void Deck::setDeckSize(int n) {
  if (!deck == 0) {
    delete deck;
    deck = 0;
  }
  size = n;
  deck = new int[size * 52];
  populateDeck(deck);
  counter = 0;
}

int Deck::drawCard() {
  if (counter == size * 52) {
    return 0;
  } else {
    counter++;
    return deck[counter - 1];
  }
}

int Deck::remainingCards() {
  return size * 52 - counter;
}
