#include "window.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent) {

    readSettings();
    layout = new QVBoxLayout();
    ctlayout = new QVBoxLayout();
    ctlayout->setContentsMargins(0,0,0,0);

    centralwidget = new QWidget();
    centralwidget->setStyleSheet("background-color: #bdbdbd;");
    setCentralWidget(centralwidget);

    this->setLayout(layout);

    centralwidget->setLayout(ctlayout);

}

void Window::readSettings() {
    auto settings = new QSettings("XIO", "Roe");
    auto _geometry = settings->value("geometry");
    this->restoreGeometry(_geometry.toByteArray());
}

void Window::closeEvent(QCloseEvent *event){
    auto settings = new QSettings("XIO", "Roe");
    settings->setValue("geometry", this->saveGeometry());
}


Window::~Window() {}

