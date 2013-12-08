#include <QtGui>
#include "blackjack.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  Blackjack blackjack;
  blackjack.show();

  //  connect(blackjack.quitButton, SIGNAL(clicked()), app, SLOT(quit()));

  return app.exec();
}
