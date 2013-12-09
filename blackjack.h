#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#include <QtGui>

class BlackjackCanvas;

class Blackjack : public QWidget
{
  Q_OBJECT

 public:
  Blackjack();

 private:
  BlackjackCanvas* canvas;
  QPushButton* startButton;
  QPushButton* hitButton;
  QPushButton* doubleButton;
  QPushButton* standButton;
  QPushButton* foldButton;
  QPushButton* dealButton;
  QPushButton* countButton;
};

#endif
