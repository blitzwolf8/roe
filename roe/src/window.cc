
#include <QMenuBar>
#include <QKeySequence>


#include "window.h"


Window::Window(QWidget *parent)
    : QMainWindow(parent) {

    readSettings();
    layout = new QVBoxLayout();
    layout->setContentsMargins(0,0,0,0);

    createActions();
    centralwidget = new QWidget();
    centralwidget->setStyleSheet("background-color: #bdbdbd;");
    centralwidget->setLayout(layout);
    setCentralWidget(centralwidget);

}

void Window::readSettings() {
    auto settings = QSettings("XIO", "Roe");
    auto _geometry = settings.value("geometry");
    this->restoreGeometry(_geometry.toByteArray());
}

void Window::closeEvent(QCloseEvent *event){
    auto settings = QSettings("XIO", "Roe");
    settings.setValue("geometry", this->saveGeometry());
}

void Window::createActions() {
    auto fileMenu = this->menuBar()->addMenu("&File");
    auto editMenu = this->menuBar()->addMenu("&Edit");
    auto helpMenu = this->menuBar()->addMenu("&Help");

    auto action_new = new QAction(QIcon::fromTheme("document-new"), "New File", this);
    auto action_open = new QAction(QIcon::fromTheme("document-open"), "Open File...", this);
    auto action_save = new QAction(QIcon::fromTheme("document-save"), "Save", this);
    auto action_saveas = new QAction("Save As...", this);
    auto action_exit = new QAction(QIcon::fromTheme("application-exit"), "Exit", this);
    auto action_close = new QAction("Close Document", this);
    auto action_undo = new QAction(QIcon::fromTheme("document-undo"), "Undo", this);
    auto action_about = new QAction("About Roe", this);

    action_new->setShortcut(QKeySequence::New);
    action_open->setShortcut(QKeySequence::Open);
    action_save->setShortcut(QKeySequence::Save);
    action_saveas->setShortcut(QKeySequence::SaveAs);
    action_exit->setShortcut(QKeySequence::Quit);
    action_close->setShortcut(QKeySequence::Close);
    action_undo->setShortcut(QKeySequence::Undo);

    fileMenu->addAction(action_new);
    fileMenu->addSeparator();
    fileMenu->addAction(action_open);
    fileMenu->addMenu("Recent Files");
    fileMenu->addSeparator();
    fileMenu->addAction(action_save);
    fileMenu->addAction(action_saveas);
    fileMenu->addSeparator();
    fileMenu->addAction(action_close);
    fileMenu->addSeparator();
    fileMenu->addAction(action_exit);

    editMenu->addAction(action_undo);
    helpMenu->addAction(action_about);


}

Window::~Window() {}

