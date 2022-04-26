#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QPlainTextEdit>
#include <QTextDocument>



class Document : public QObject {
    Q_OBJECT
public:
    explicit Document(QObject *parent = nullptr);

private:
    QTextDocument *_document;

};










#endif
