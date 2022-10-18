#include "editor.h"

#include <QAction>
#include <QCloseEvent>
#include <QIcon>
#include <QMainWindow>
#include <QPixmap>
#include <QSettings>
#include <QVBoxLayout>
#include <QWidget>

class Window : public QMainWindow {
  Q_OBJECT

public:
  explicit Window(QWidget *parent = nullptr);
  ~Window();

  void readSettings();
  void closeEvent(QCloseEvent *event);
  void createActions();
  void about();
  void feedback();
  void help();

public slots:
  void setTitle(const QString&);

private:
  QMenuBar *menubar;
  QWidget *centralwidget;
  PlainTextEditor *editor;
};