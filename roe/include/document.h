#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "base/document_base.h"
#include <QPlainTextEdit>

class PlainTextDocument : public Document {
  Q_OBJECT
public:
  explicit PlainTextDocument(Document *parent = nullptr);
  ~PlainTextDocument();

public:
  Q_INVOKABLE virtual void write() override;
  Q_INVOKABLE virtual void save() override;
  Q_INVOKABLE virtual void saveAs() override;
  Q_INVOKABLE virtual void open() override;
  Q_INVOKABLE void open(const QString& );
  Q_INVOKABLE virtual void close() override;
  Q_INVOKABLE virtual QString fileName() const override;

  bool isOpened() const;
  bool isModified() const;
  QPlainTextEdit *textEdit() const;

signals:
  void statusChanged(StatusFlags);
  void nameChanged(QString);

  
  private:
    StatusFlags status;
    QPlainTextEdit *ptextEdit;
    QString _filename;
};

#endif