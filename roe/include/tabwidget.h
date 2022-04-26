#ifndef TABWIDGET_H
#define TABWIDGET_H

#include "editor.h"

#include <QTabWidget>
#include <QWidget>


class TabWidget : public QTabWidget {
    Q_OBJECT
public:
    explicit TabWidget(QWidget *parent=nullptr);

public slots:
    void newDocument();
    void closeDocument(quint16);
    void savedDocument(quint16);
    void openDocument();

};


#endif // TABWIDGET_H
