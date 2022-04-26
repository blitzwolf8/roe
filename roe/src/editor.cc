#include "editor.h"
#include <QFontMetricsF>
#include <QTextOption>
#include <QFileInfo>
#include <QFileDialog>
#include <QTextStream>
#include <QIODevice>
#include <QFile>
#include <QDir>


Editor::Editor(OpenMode _mode, QWidget *parent)
    : QWidget(parent), mode(_mode) {

    auto attr = Qt::WA_DeleteOnClose;
    this->setAttribute(attr, true);
    layout = new QVBoxLayout();
    layout->setContentsMargins(0,0,0,0);
    setLayout(layout);

    fileName = "";
    textEdit = new QPlainTextEdit(this);
    textEdit->setStyleSheet("background-color: #fdfdfd ;");
    textEdit->setTabStopDistance(QFontMetricsF(textEdit->font()).horizontalAdvance(' ') * 4);
    textEdit->setWordWrapMode(QTextOption::NoWrap);

    doc = new Document(this);
    textEdit->setDocument(doc->document());

    if(mode == OpenMode::NEW)
        New();
    if(mode == OpenMode::EXISTING)
        Open();
    layout->addWidget(textEdit);
}

void Editor::Open() {
    fileName = QFileDialog::getOpenFileName(this, "Open File");
    if(fileName != ""){
        auto file = QFile(fileName);
        if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
            return;
        auto stream = QTextStream(&file);
        auto contents = stream.readAll();
        textEdit->setPlainText(contents);
    }
}

void Editor::New() {
    auto newfile = QDir::homePath() + "/Untitled";
    auto file = QFile(newfile);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;
}

QPlainTextEdit* Editor::editor() const {
    return textEdit;
}












