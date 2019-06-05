#ifndef CONTENT_H
#define CONTENT_H

#include <QtWidgets>

#include "dbwrapper.h"

class Content : public QWidget
{
    Q_OBJECT
public:
    explicit Content(QWidget *parent = nullptr);
    ~Content() override = default;

private:
    QTableView* tableView {nullptr};
    QSplitter* splitter;
    QTextEdit* commandEdit;
    QTextEdit* logEdit;

    DBWrapper* dbWrapper;

public:
    void onOpeningDBFile (const QString& fileName);

signals:

public slots:
    void onDbError(const QString&);
    void onRunning();
};

#endif // CONTENT_H
