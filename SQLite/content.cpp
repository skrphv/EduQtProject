#include "content.h"

Content::Content(QWidget *parent)
    : QWidget(parent)
    , tableView (new QTableView)
    , splitter (new QSplitter(Qt::Vertical))
    , commandEdit (new QTextEdit)
    , logEdit (new QTextEdit)
    , dbWrapper (new DBWrapper(this))

{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    tableView->setModel(dbWrapper->getSqlQueryModel());

    splitter->addWidget(tableView);
    splitter->addWidget(commandEdit);
    splitter->addWidget(logEdit);

    QVBoxLayout* vLayout {new QVBoxLayout{this}};
    vLayout->setMargin(0);
    vLayout->setSpacing(5);

    vLayout->addWidget(splitter);

    connect(dbWrapper, &DBWrapper::dbError, this, &Content::onDbError);
}

void Content::onOpeningDBFile(const QString &fileName)
{
    dbWrapper->openDB(fileName);
}

void Content::onDbError(const QString & msg)
{
    logEdit->append( QString {"%1  %2"}
                     .arg(QDateTime::currentDateTime().toString())
                     .arg(msg)                                     );
}

void Content::onRunning()
{
    dbWrapper->execQuery(commandEdit->toPlainText());
}
