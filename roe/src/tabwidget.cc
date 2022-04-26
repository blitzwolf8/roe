#include "tabwidget.h"



TabWidget::TabWidget(QWidget *parent)
    : QTabWidget(parent) {

    this->setDocumentMode(true);
    this->setTabsClosable(true);

    QObject::connect(this, &QTabWidget::tabCloseRequested, this, &TabWidget::closeDocument);

}

void TabWidget::newDocument() {
    auto idx = addTab(new Editor(OpenMode::NEW, this), "Untitled");
    setCurrentIndex(idx);
}

void TabWidget::openDocument() {
    auto idx = addTab(new Editor(OpenMode::EXISTING, this), "");
    setCurrentIndex(idx);
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
