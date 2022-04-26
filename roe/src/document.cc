#include "document.h"
#include <QFont>

Document::Document(QObject *parent)
    : QObject(parent) {

    _document = new QTextDocument();
    auto layout = QPlainTextDocumentLayout(this->_document);
    _document->setDocumentLayout(&layout);
    _document->setDefaultFont(QFont("Times New Roman"));
    _document->setTextWidth(24);
}

QTextDocument * Document::document() const {
    return _document;
}
