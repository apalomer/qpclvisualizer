// Qt
#include <QApplication>

// Custom Widget
#include "qpclvisualizer.h"

int main(int argc, char* argv[])
{
  // Start Qt Application
  QApplication app(argc, argv);

  // Create Qt Widget
  QPCLVisualizer* qpclvisualizer = new QPCLVisualizer();

  // Show widget
  qpclvisualizer->show();

  // Run
  return app.exec();
}
