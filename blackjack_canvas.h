#ifndef BLACKJACK_CANVAS_H_
#define BLACKJACK_CANVAS_H_
#include <QGraphicsPixmapItem>
#include <QtGui>

class Deck;

class BlackjackCanvas : public QWidget
{
  Q_OBJECT

    public:
  BlackjackCanvas(QWidget* parent);

 signals:
  void needsButtonChange(QString str);

  public slots:
  void startPress();
  void hitPress();
  //  void doublePress();
  void standPress();
  //  void foldPress();
  void dealPress();
  void newHand();
  int computerHit();
  //  void quitPress();

 protected:
  void paintEvent(QPaintEvent* event);
  QLineEdit* temp;
  QGridLayout* grid;
  QLabel* p1;
  QLabel* p2;
  QLabel* p3;
  QLabel* p4;
  QLabel* p5;
  QLabel* c1;
  QLabel* c2;
  QLabel* c3;
  QLabel* c4;
  QLabel* c5;
  int player[5];
  int pCounter;
  int computer[5];
  int cCounter;
  char buffer[100];
  /* void keyPressEvent(QKeyEvent* event); */
  /* void keyReleaseEvent(QKeyEvent* event); */

  private slots:
    //  void timerTicked();

 private:
  Deck* deck;
  
  void reset();

  enum State { BEFORE_PLAY, PLAYING, AFTER_HAND } state;

  //   QTimer* timer;

  static const int WIDTH = 700;
  static const int HEIGHT = 300;
  static const int NUM_DECKS = 4;
};

#endif
