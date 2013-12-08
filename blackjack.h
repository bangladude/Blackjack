#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#include <QtGui>

class BlackjackCanvas;

class Blackjack : public QWidget
{
  Q_OBJECT

    public:
  Blackjack();
  //  QPushButton* quitButton;

  private slots:
    //  void changeButtonText(QString str);

 private:
  BlackjackCanvas* canvas;
  QPushButton* startButton;
  QPushButton* hitButton;
  QPushButton* doubleButton;
  QPushButton* standButton;
  QPushButton* foldButton;
  QPushButton* dealButton;
  //  QPushButton* quitButton;
};

#endif
