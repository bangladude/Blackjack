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
  countButton = new QPushButton("Count", this);
  
  QHBoxLayout* buttons = new QHBoxLayout(this);
  buttons->addWidget(startButton);
  buttons->addWidget(hitButton);
  buttons->addWidget(standButton);
  buttons->addWidget(dealButton);
  buttons->addWidget(countButton);

  layout->addItem(buttons);

  connect(startButton, SIGNAL(clicked()), canvas, SLOT(startPress()));
  connect(hitButton, SIGNAL(clicked()), canvas, SLOT(hitPress()));
  connect(standButton, SIGNAL(clicked()), canvas, SLOT(standPress()));
  connect(dealButton, SIGNAL(clicked()), canvas, SLOT(dealPress()));
  connect(countButton, SIGNAL(clicked()), canvas, SLOT(countPress()));

  connect(canvas, SIGNAL(needsButtonChange(QString)), this, 
	  SLOT(changeButtonText(QString)));
}
