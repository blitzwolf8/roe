#include "document.h"

#include <QIODevice>
#include <QTextStream>
#include <QFile>

PlainTextDocument::PlainTextDocument(Document *parent) : Document(parent) {
  ptextEdit = new QPlainTextEdit();
}

PlainTextDocument::~PlainTextDocument() {}

void PlainTextDocument::write() {}

void PlainTextDocument::open(const QString &file) {
  if (status == StatusFlags::Modified) {
    close();
    open(file);
  }
  else {
    _filename = file;
    emit statusChanged(StatusFlags::Opened);
    emit nameChanged(_filename);
    QFile file(_filename);
    if(file.open(QFile::ReadWrite)){
      QTextStream strm(&file);
      QString data = strm.readAll();
      ptextEdit->setPlainText(data);
    }
  }
}

void PlainTextDocument::open() {}

void PlainTextDocument::read() {}

void PlainTextDocument::save() {}

void PlainTextDocument::saveAs() {}

void PlainTextDocument::close() {}

QString PlainTextDocument::fileName() const { return _filename; }

bool PlainTextDocument::isOpened() const {
  return status == StatusFlags::Opened;
}

bool PlainTextDocument::isModified() const {
  return status == StatusFlags::Modified;
}

QPlainTextEdit *PlainTextDocument::textEdit() const { return ptextEdit; }