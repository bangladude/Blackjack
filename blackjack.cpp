#include <QtGui>
#include "blackjack.h"
#include "blackjack_canvas.h"
#include <cstring>
#include <string>

Blackjack::Blackjack()
{
  setWindowTitle("Blackjack");

  canvas = new BlackjackCanvas(this);
  QVBoxLayout* layout = new QVBoxLayout(this);
  layout->addWidget(canvas);
  
  startButton = new QPushButton("Start", this);
  hitButton = new QPushButton("Hit", this);
  //  doubleButton = new QPushButton("Double", this);
  standButton = new QPushButton("Stand", this);
  //  foldButton = new QPushButton("Fold", this);
  //  quitButton = new QPushButton("Quit", this);
  dealButton = new QPushButton("Deal", this);
  
  QHBoxLayout* buttons = new QHBoxLayout(this);
  buttons->addWidget(startButton);
  buttons->addWidget(hitButton);
  //  buttons->addWidget(doubleButton);
  buttons->addWidget(standButton);
  //  buttons->addWidget(foldButton);
  buttons->addWidget(dealButton);
  //  buttons->addWidget(quitButton);

  layout->addItem(buttons);

  connect(startButton, SIGNAL(clicked()), canvas, SLOT(startPress()));
  connect(hitButton, SIGNAL(clicked()), canvas, SLOT(hitPress()));
  //  connect(doubleButton, SIGNAL(clicked()), canvas, SLOT(doublePress()));
  connect(standButton, SIGNAL(clicked()), canvas, SLOT(standPress()));
  //  connect(foldButton, SIGNAL(clicked()), canvas, SLOT(foldPress()));
  connect(dealButton, SIGNAL(clicked()), canvas, SLOT(dealPress()));


  connect(canvas, SIGNAL(needsButtonChange(QString)), this, 
	  SLOT(changeButtonText(QString)));

  // QPixmap p1 = QPixmap("images/1.gif");
  // QLabel* mylabel = new QLabel(canvas);
  // mylabel->setPixmap(p1);
  //  layout->addWidget(mylabel);
  //  p1.show();
  //  mylabel->show();
}

// void Blackjack::changeButtonText(QString str)
// {
//   //controlButton->setText(str);
// }
