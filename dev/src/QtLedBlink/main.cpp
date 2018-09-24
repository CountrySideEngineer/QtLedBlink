#include "qtledblinkmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtLEDBlinkMainWindow w;
#ifdef WINDOW_FULL_SCREEN
    w.showFullScreen();
#else
    w.show();
#endif

    return a.exec();
}
