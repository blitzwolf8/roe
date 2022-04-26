#ifndef EDITOR_H
#define EDITOR_H

#include "document.h"
#include <QWidget>
#include <QCloseEvent>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QFile>

enum class OpenMode { NEW, EXISTING };


class Editor : public QWidget {
    Q_OBJECT
public:
    explicit Editor(OpenMode _mode, QWidget *parent = nullptr);
    void New();
    void Open();
    void Close();
    void Save();
    void SaveAs();
    QPlainTextEdit* editor() const;
    QString documentName();
    void closeEvent(QCloseEvent *event);

private:
    OpenMode mode;
    QVBoxLayout *layout;
    QPlainTextEdit *textEdit;
    QString fileName;
    Document *doc;
    QFile *file;
};


#endif // EDITOR_H
