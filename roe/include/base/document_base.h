#ifndef DOCUMENT_BASE_H
#define DOCUMENT_BASE_H

#include <QObject>
#include <QFrame>

class Document : public QObject {
  Q_OBJECT

  Q_PROPERTY(bool modified READ isModified)
  Q_PROPERTY(bool opened READ isOpened)

public:
  explicit Document(QObject *parent = nullptr) : QObject(parent) {}
  ~Document() {}

public:
  Q_INVOKABLE virtual void write() = 0;
  Q_INVOKABLE virtual void save() = 0;
  Q_INVOKABLE virtual void saveAs() = 0;
  Q_INVOKABLE virtual void close() = 0;
  Q_INVOKABLE virtual QString fileName() const = 0;

  enum class StatusFlags { Opened, Closed, Modified , Saved};
  

public:
  bool isOpened() const;
  bool isModified() const;
};

#endif