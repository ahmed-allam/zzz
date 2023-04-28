#include "qt_multithreaded_cuda.h"
#include <QtWidgets/QApplication>
#include <QtGui/qscreen.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    QScreen* screen = a.primaryScreen();
    QRect  screenGeometry = screen->availableGeometry();
    //qreal dpi = QGuiApplication::primaryScreen()->logicalDotsPerInch();
    //qreal dpi = screen->logicalDotsPerInch();

    QT_Multithreaded_Cuda_class w(screenGeometry.width(), screenGeometry.height());
    w.show();    
    return a.exec();
}
