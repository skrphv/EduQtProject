#ifndef CONTENT_H
#define CONTENT_H

#include <QWidget>
#include <QTextEdit>
#include <QListView>
#include <QListWidget>
#include <QSplitter>
#include <QString>
#include <QStandardItemModel>

class Content : public QWidget
{
    Q_OBJECT
public:
    explicit Content(QWidget *parent = nullptr);
    ~Content() override = default;

protected:
    QTextEdit*   textEdit   {new QTextEdit};
    QListView*   listView   {new QListView};
    QSplitter*   hsplitter  {new QSplitter(Qt::Horizontal)  };
    QSplitter*   vsplitter  {new QSplitter(Qt::Vertical)  };
    QTextEdit*   loggerEdit {new QTextEdit};

    QStandardItemModel* listModel {new QStandardItemModel};

    void logMsg (const QString& msg);

private:
    void processText (const QString& text);


public slots:
    void processTextFile (const QString& filename);

signals:
    void logMessaging (const QString&);
    void processText();
};

#endif // CONTENT_H
