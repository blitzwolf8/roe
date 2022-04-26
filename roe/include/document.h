#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QPlainTextEdit>
#include <QTextDocument>



class Document : public QObject {
    Q_OBJECT
public:
    explicit Document(QObject *parent = nullptr);
    QTextDocument *document() const;
private:
    QTextDocument *_document;

};










#endif
