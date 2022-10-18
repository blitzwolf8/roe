#include "editor.h"

#include <QFileDialog>
#include <QVBoxLayout>

PlainTextEditor::PlainTextEditor(QWidget *parent) : QWidget(parent) {

  auto _layout = new QVBoxLayout(this);
  setLayout(_layout);
  m_document = new PlainTextDocument();

  auto _edit = m_document->textEdit();
  _layout->addWidget(_edit);
}

PlainTextEditor::~PlainTextEditor() { delete m_document; }

void PlainTextEditor::open() {
  auto file = QFileDialog::getOpenFileName(this, "Open File");
  if(!file.isEmpty()){
    m_document->open(file);
  }
}

void PlainTextEditor::New() {}

void PlainTextEditor::cut() {}

void PlainTextEditor::copy() {}

void PlainTextEditor::setWrapMode() {}

void PlainTextEditor::zoomIn() {}

void PlainTextEditor::zoomOut() {}

void PlainTextEditor::replace() {}

void PlainTextEditor::undo() {}

void PlainTextEditor::redo() {}

void PlainTextEditor::setFont() {}

void PlainTextEditor::close() {}

void PlainTextEditor::save() {}