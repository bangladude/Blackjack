#include <QtGui>
#include "blackjack_canvas.h"
#include "deck.h"
#include "strategy.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <QDebug>
#include <QTextStream>



BlackjackCanvas::BlackjackCanvas(QWidget* parent)
  : QWidget(parent)
{

  temp = new QLineEdit(this);

  QPalette Pal(palette());
  Pal.setColor(QPalette::Background, Qt::darkGreen);
  this->setAutoFillBackground(true);
  this->setPalette(Pal);

  deck = new Deck();
  deck->setDeckSize(NUM_DECKS);

  setFixedSize(WIDTH, HEIGHT);
  
  grid = new QGridLayout(this);
  p1 = new QLabel(this);
  p2 = new QLabel(this);
  p3 = new QLabel(this);
  p4 = new QLabel(this);
  p5 = new QLabel(this);
  c1 = new QLabel(this);
  c2 = new QLabel(this);
  c3 = new QLabel(this);
  c4 = new QLabel(this);
  c5 = new QLabel(this);
  grid->addWidget(c1, 0, 0);
  grid->addWidget(c2, 0, 1);
  grid->addWidget(c3, 0, 2);
  grid->addWidget(c4, 0, 3);
  grid->addWidget(c5, 0, 4);
  grid->addWidget(p1, 1, 0);
  grid->addWidget(p2, 1, 1);
  grid->addWidget(p3, 1, 2);
  grid->addWidget(p4, 1, 3);
  grid->addWidget(p5, 1, 4);

  reset();
}

void BlackjackCanvas::newHand() {
  for(int i = 0; i < 5; i++) {
    player[i] = -1;
    computer[i] = -1;
  }
  pCounter = 0;
  cCounter = 0;
  
  c1->setPixmap(QPixmap(""));
  c2->setPixmap(QPixmap(""));
  c3->setPixmap(QPixmap(""));
  c4->setPixmap(QPixmap(""));
  c5->setPixmap(QPixmap(""));
  p1->setPixmap(QPixmap(""));
  p2->setPixmap(QPixmap(""));
  p3->setPixmap(QPixmap(""));
  p4->setPixmap(QPixmap(""));
  p5->setPixmap(QPixmap(""));
}

void BlackjackCanvas::startPress()
{
  if(state == BEFORE_PLAY) {
    reset();
  } else if (state == AFTER_HAND) {
    newHand();
  }
  state = PLAYING;
  dealPress();
  setFocus(Qt::OtherFocusReason);
}

int value(int card) {
  if (card % 13 == 1) {
    return 11;
  } else if (card % 13 >= 10 || card % 13 == 0) {
    return 10;
  } else {
    return card % 13;
  }
}

void BlackjackCanvas::hitPress() {
  int playerSum = 0;
  for(int i = 0; i < pCounter; i++) {
    playerSum += value(player[i]);
  }
  //  sprintf(buffer, "CARD VALUES: %i, %i", value(player[0]), value(player[1]));
  //  temp->insert(QString(buffer));
  if(playerSum >= 17) {
    QMessageBox messageBox;
    messageBox.setWindowTitle("Are you sure?");
    messageBox.setText("Do you really want to hit?");
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);
    if(messageBox.exec() == QMessageBox::No) {
      return;
    }
  }
  int card = deck->drawCard();
  player[pCounter] = card;
  switch(pCounter) {
  case 2:
    sprintf(buffer, "images/%i.gif", card);
    p3->setPixmap(QPixmap(buffer));
    pCounter++;
    break;
  case 3:
    sprintf(buffer, "images/%i.gif", card);
    p4->setPixmap(QPixmap(buffer));
    pCounter++;
    break;
  case 4:
    sprintf(buffer, "images/%i.gif", card);
    p5->setPixmap(QPixmap(buffer));
    pCounter++;
    break;
  }
  playerSum += value(card);
  if(playerSum > 21) {
    QMessageBox messageBox;
    messageBox.setWindowTitle("Bust");
    messageBox.setText("Sorry, you went over 21");
    messageBox.setStandardButtons(QMessageBox::Ok);//QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::Ok);
    if(messageBox.exec() == QMessageBox::Ok) {
      return;
    }
  }
}

// void BlackjackCanvas::doublePress() {
// }

void mySleep(unsigned int time) {
  clock_t goal = time + clock();
  while (clock() < goal) {}
}

int BlackjackCanvas::computerHit() {
  int card = deck->drawCard();
  computer[cCounter] = card;
  switch(cCounter) {
  case 2:
    sprintf(buffer, "images/%i.gif", card);
    c3->setPixmap(QPixmap(buffer));
    cCounter++;
    break;
  case 3:
    sprintf(buffer, "images/%i.gif", card);
    c4->setPixmap(QPixmap(buffer));
    cCounter++;
    break;
  case 4:
    sprintf(buffer, "images/%i.gif", card);
    c5->setPixmap(QPixmap(buffer));
    cCounter++;
    break;
  }
  return value(card);
}


void BlackjackCanvas::standPress() {
  sleep(1);
  sprintf(buffer, "images/%i.gif", computer[1]);

  c2->setPixmap(QPixmap(buffer));
  int computerSum = 0;
  computerSum += value(computer[1]) + value(computer[0]);

  while (computerSum < 17 && cCounter <= 5) {
    computerSum += computerHit();
  }

  int pSum = 0;
  for (int i = 0; i < pCounter; i++) {
    pSum += value(player[i]);
  }

  sprintf(buffer, "p:%i, c:%i", pSum, computerSum);
  temp->insert(QString(buffer));
  if(computerSum > 21) {
    QMessageBox messageBox;
    messageBox.setWindowTitle("Hand Over");
    messageBox.setText("The dealer went over 21 - you win");
    messageBox.setStandardButtons(QMessageBox::Ok);
    messageBox.setDefaultButton(QMessageBox::Ok);
    if(messageBox.exec() == QMessageBox::Ok) {
      return;
    }
  } else if(pSum < computerSum) {
    QMessageBox messageBox;
    messageBox.setWindowTitle("Hand Over");
    messageBox.setText("Sorry, you lose");
    messageBox.setStandardButtons(QMessageBox::Ok);//QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::Ok);
    if(messageBox.exec() == QMessageBox::Ok) {
      return;
    }
  } else if(pSum == computerSum) {
    QMessageBox messageBox;
    messageBox.setWindowTitle("Hand Over");
    messageBox.setText("Push");
    messageBox.setStandardButtons(QMessageBox::Ok);//QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::Ok);
    if(messageBox.exec() == QMessageBox::Ok) {
      return;
    }
  }
  state = AFTER_HAND;
}

// void BlackjackCanvas::foldPress() {
//   dealPress();
// }

void BlackjackCanvas::dealPress() {
  if(deck->remainingCards() < 10) {
    QMessageBox messageBox;
    messageBox.setWindowTitle("New Deck");
    messageBox.setText("The 4 decks are being reshuffled");
    messageBox.setStandardButtons(QMessageBox::Ok);
    messageBox.setDefaultButton(QMessageBox::Ok);
    if(messageBox.exec() == QMessageBox::Ok) {
      reset();
    }
  } else {
    newHand();
    int card = deck->drawCard();
    sprintf(buffer, "images/%i.gif", card);
    c1->setPixmap(QPixmap(buffer));
    computer[0] = card;
    card = deck->drawCard();

    c2->setPixmap(QPixmap("images/blank_black.gif"));
    computer[1] = card;
    card = deck->drawCard();
    sprintf(buffer, "images/%i.gif", card);
    p1->setPixmap(QPixmap(buffer));
    player[0] = card;
    card = deck->drawCard();
    sprintf(buffer, "images/%i.gif", card);
    p2->setPixmap(QPixmap(buffer));
    player[1] = card;
    pCounter = 2;
    cCounter = 2;
  }
}

void BlackjackCanvas::reset()
{
  deck->setDeckSize(NUM_DECKS);
  newHand();
  update();
}

void BlackjackCanvas::paintEvent(QPaintEvent*)
{
  QPainter p(this);
  
  // draw frame
  p.drawRect(0, 0, WIDTH-1, HEIGHT-1);
}
