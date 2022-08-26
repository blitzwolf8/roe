#ifndef DIALOGS_H
#define DIALOGS_H

#include <QWidget>

class SearchDialog : public QWidget {
  Q_OBJECT
public:
  explicit SearchDialog(QWidget *parent = nullptr);
};

class GotoDialog : public QWidget {
  Q_OBJECT
public:
  explicit GotoDialog(QWidget *parent = nullptr);
};

#endif