#ifndef DECK_H_
#define DECK_H_

class Deck {
  
 public:
  Deck();
  void setDeckSize(int n);
  int drawCard();

 private:
  void populateDeck(int* deck);
  int* deck;
  int counter;
  int size;
};

#endif
