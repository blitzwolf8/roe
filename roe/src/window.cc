#include "window.h"

#include <QKeySequence>
#include <QMenuBar>
#include <QSettings>
#include <QVBoxLayout>

Window::Window(QWidget *parent) : QMainWindow(parent) {

  resize(640, 520);
  readSettings();
  setContentsMargins(0, 0, 0, 0);
  menubar = menuBar();

  centralwidget = new QWidget(this);
  setCentralWidget(centralwidget);
  auto _layout = new QVBoxLayout(centralwidget);
  _layout->setContentsMargins(0, 0, 0, 0);

  editor = new PlainTextEditor(centralwidget);
  createActions();

  _layout->addWidget(editor);
}

void Window::readSettings() {
  auto settings = QSettings("XIO", "pi");
  auto _geometry = settings.value("geometry");
  this->restoreGeometry(_geometry.toByteArray());
}

void Window::closeEvent(QCloseEvent *event) {
  auto settings = QSettings("XIO", "pi");
  settings.setValue("geometry", this->saveGeometry());
}

void Window::setTitle(const QString &_title) {
  QString title = QString(_title).append(" - Note");
  setWindowTitle(title);
}

void Window::createActions() {
  auto fileMenu = menubar->addMenu("&File");
  auto editMenu = menubar->addMenu("&Edit");
  auto viewMenu = menubar->addMenu("&View");
  auto helpMenu = menubar->addMenu("&Help");

  auto action_new =
      new QAction(QIcon::fromTheme("document-new"), "New File", this);
  auto action_open =
      new QAction(QIcon::fromTheme("document-open"), "Open File...", this);
  auto action_save =
      new QAction(QIcon::fromTheme("document-save"), "Save", this);
  auto action_saveas = new QAction("Save As...", this);
  auto action_exit =
      new QAction(QIcon::fromTheme("application-exit"), "Exit", this);
  auto action_close = new QAction("Close Document", this);

  auto action_undo =
      new QAction(QIcon::fromTheme("document-undo"), "Undo", this);
  auto action_redo = new QAction("Redo", this);
  auto action_cut = new QAction("Cut", this);
  auto action_copy = new QAction("Copy", this);

  auto action_paste = new QAction("Paste", this);
  auto action_find = new QAction("Find", this);
  auto action_replace = new QAction("Replace", this);
  auto action_font = new QAction("Fonts", this);
  auto action_zoomin = new QAction("Zoom In", this);
  auto action_zoomout = new QAction("Zoom Out", this);
  auto action_wrap = new QAction("Word Wrap", this);

  auto action_about = new QAction("About Roe", this);
  auto action_feedback = new QAction("Feedback", this);
  auto action_help = new QAction("Help", this);

  action_new->setShortcut(QKeySequence::New);
  action_open->setShortcut(QKeySequence::Open);
  action_save->setShortcut(QKeySequence::Save);
  action_saveas->setShortcut(QKeySequence::SaveAs);
  action_exit->setShortcut(QKeySequence::Quit);
  action_close->setShortcut(QKeySequence::Close);
  action_undo->setShortcut(QKeySequence::Undo);
  action_redo->setShortcut(QKeySequence::Redo);
  action_cut->setShortcut(QKeySequence::Cut);
  action_copy->setShortcut(QKeySequence::Copy);
  action_paste->setShortcut(QKeySequence::Paste);
  action_zoomin->setShortcut(QKeySequence::ZoomIn);
  action_zoomout->setShortcut(QKeySequence::ZoomOut);
  action_help->setShortcut(QKeySequence::HelpContents);

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
  editMenu->addAction(action_redo);
  editMenu->addSeparator();
  editMenu->addAction(action_cut);
  editMenu->addAction(action_copy);
  editMenu->addAction(action_paste);
  editMenu->addSeparator();
  editMenu->addAction(action_find);
  editMenu->addAction(action_replace);

  viewMenu->addAction(action_font);
  viewMenu->addSeparator();
  viewMenu->addAction(action_zoomin);
  viewMenu->addAction(action_zoomout);

  helpMenu->addAction(action_about);
  helpMenu->addAction(action_feedback);
  helpMenu->addAction(action_help);

  QObject::connect(action_open, &QAction::triggered, editor,
                   &PlainTextEditor::open);
  QObject::connect(action_new, &QAction::triggered, editor,
                   &PlainTextEditor::New);
  QObject::connect(action_save, &QAction::triggered, editor,
                   &PlainTextEditor::save);
  QObject::connect(action_saveas, &QAction::triggered, editor,
                   &PlainTextEditor::save);
  QObject::connect(action_close, &QAction::triggered, editor,
                   &PlainTextEditor::close);
  QObject::connect(action_exit, &QAction::triggered, this, &Window::close);
  QObject::connect(action_undo, &QAction::triggered, editor,
                   &PlainTextEditor::undo);
  QObject::connect(action_redo, &QAction::triggered, editor,
                   &PlainTextEditor::redo);
  QObject::connect(action_cut, &QAction::triggered, editor,
                   &PlainTextEditor::cut);
  QObject::connect(action_copy, &QAction::triggered, editor,
                   &PlainTextEditor::copy);
  QObject::connect(action_find, &QAction::triggered, editor,
                   &PlainTextEditor::find);
  QObject::connect(action_replace, &QAction::triggered, editor,
                   &PlainTextEditor::replace);
  QObject::connect(action_font, &QAction::triggered, editor,
                   &PlainTextEditor::setFont);
  QObject::connect(action_zoomin, &QAction::triggered, editor,
                   &PlainTextEditor::zoomIn);
  QObject::connect(action_zoomout, &QAction::triggered, editor,
                   &PlainTextEditor::zoomOut);
  QObject::connect(action_wrap, &QAction::triggered, editor,
                   &PlainTextEditor::setWrapMode);
  QObject::connect(action_about, &QAction::triggered, this, &Window::about);
  QObject::connect(action_feedback, &QAction::triggered, this,
                   &Window::feedback);
  QObject::connect(action_help, &QAction::triggered, this, &Window::help);
}

Window::~Window() {}

void Window::feedback() {}

void Window::help() {}

void Window::about() {}