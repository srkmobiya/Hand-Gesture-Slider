#include "mainwindow.h"
#include <QApplication>
#include<QSplashScreen>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap("gesture.jpg"); //Insert your splash page image here
      QSplashScreen splash(pixmap);
      splash.show();

      splash.showMessage(QObject::tr("Initiating your program now..."),
                      Qt::AlignLeft | Qt::AlignTop, Qt::black);  //This line represents the alignment of text, color and position

      qApp->processEvents();//This is used to accept a click on the screen so that user can cancel the screen*/

    MainWindow w;
    w.setWindowIcon(QIcon("icon.ico"));
    w.setWindowTitle("Hand Gesture Control");
    w.show();

    return a.exec();
}
