#include "window.h"

#include <QApplication>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationVersion("1.0");
    QCoreApplication::setOrganizationDomain("org.roe.xio");
    QCoreApplication::setOrganizationName("XIO");
    QCoreApplication::setApplicationName("Roe");

    QApplication a(argc, argv);
    Window w;
    w.show();
    return a.exec();
}
