#include "window.h"

#include <QApplication>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationVersion("1.0.0");
    QCoreApplication::setOrganizationDomain("org.xio.roe");
    QCoreApplication::setOrganizationName("XIO");
    QCoreApplication::setApplicationName("roe");
    
    QApplication a(argc, argv);
    Window w;
    w.show();
    return a.exec();
}
