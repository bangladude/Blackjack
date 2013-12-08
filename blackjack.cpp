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
  standButton = new QPushButton("Stand", this);
  dealButton = new QPushButton("Deal", this);
  
  QHBoxLayout* buttons = new QHBoxLayout(this);
  buttons->addWidget(startButton);
  buttons->addWidget(hitButton);
  buttons->addWidget(standButton);
  buttons->addWidget(dealButton);

  layout->addItem(buttons);

  connect(startButton, SIGNAL(clicked()), canvas, SLOT(startPress()));
  connect(hitButton, SIGNAL(clicked()), canvas, SLOT(hitPress()));
  connect(standButton, SIGNAL(clicked()), canvas, SLOT(standPress()));
  connect(dealButton, SIGNAL(clicked()), canvas, SLOT(dealPress()));


  connect(canvas, SIGNAL(needsButtonChange(QString)), this, 
	  SLOT(changeButtonText(QString)));
}
