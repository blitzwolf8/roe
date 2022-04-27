#include "tabwidget.h"



TabWidget::TabWidget(QWidget *parent)
    : QTabWidget(parent) {

    this->setDocumentMode(true);
    this->setTabsClosable(true);

    QObject::connect(this, &QTabWidget::tabCloseRequested, this, &TabWidget::closeDocument);

}

void TabWidget::newDocument() {
    auto editor = new Editor(OpenMode::NEW, this);
    auto idx = addTab(editor, "Untitled");
    setCurrentIndex(idx);
    qDebug() << "Create new tab.";
}

void TabWidget::openDocument() {
    auto idx = addTab(new Editor(OpenMode::EXISTING, this), "");
    setCurrentIndex(idx);
    qDebug() << "Open tab.";
}

void TabWidget::savedDocument(quint16 index) {
    //auto _tab = this->widget(index);
    //this->setTabText(index, qobject_cast<Editor*>(_tab)->documentName());
}

void TabWidget::closeDocument(quint16 index) {
    auto _tab = widget(index);
    if(_tab){
        _tab->deleteLater();
        _tab->close();
        removeTab(index);
    }
}
