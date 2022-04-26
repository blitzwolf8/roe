#include "editor.h"
#include <QFontMetricsF>
#include <QTextOption>
#include <QFileInfo>
#include <QFileDialog>
#include <QTextStream>
#include <QIODevice>
#include <QFile>
#include <QDir>
#include <QMessageBox>


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
        file = new QFile(fileName);
        if(!file->open(QIODevice::ReadWrite | QIODevice::Text))
            return;
        auto stream = QTextStream(file);
        auto contents = stream.readAll();
        textEdit->setPlainText(contents);
    }
}

void Editor::New() {
    auto newfile = QDir::homePath() + "/Untitled";
    file = new QFile(newfile);
    if(!file->open(QIODevice::ReadWrite | QIODevice::Text))
        return;
}

void Editor::Close() {
    if(doc->document()->isModified()){
        auto stream = QTextStream(file);
        stream << textEdit->toPlainText();
        file->close();
        textEdit->clear();
    }
}

void Editor::Save() {

}

void Editor::SaveAs() {

}

QPlainTextEdit* Editor::editor() const {
    return textEdit;
}

void Editor::closeEvent(QCloseEvent *event) {
    if(textEdit->document()->isModified()){
        auto response = QMessageBox::warning(
                    this,
                    "Roe",
                    "Do you want to save the changes you made to this document?",
                    QMessageBox::Cancel | QMessageBox::Discard | QMessageBox::Save);
        if(response == QMessageBox::Cancel)
            event->ignore();
        if(response == QMessageBox::Discard)
            event->accept();
        if(response == QMessageBox::Save)
            Save();
    }
}












