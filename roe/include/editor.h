#ifndef EDITOR_H
#define EDITOR_H

#include "document.h"

#include <QWidget>

class PlainTextEditor : public QWidget {
  Q_OBJECT

public:
  explicit PlainTextEditor(QWidget *parent = nullptr);
  ~PlainTextEditor();

  void New ();
  void open();
  void save();
  void close();
  void undo();
  void redo();
  void cut();
  void copy();
  void replace();
  void zoomIn();
  void zoomOut();
  void setWrapMode();
  void setFont();

private:
  PlainTextDocument *m_document;
};

#endif