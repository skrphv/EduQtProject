#include "dbwrapper.h"

DBWrapper::DBWrapper(QObject *parent)
    : QObject(parent)
    , sqlQueryModel (new QSqlQueryModel)
{

}

void DBWrapper::openDB(const QString &filename)
{
    auto db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(filename);

    if (!db.open())
    {
        emit dbError(db.lastError().text());
    }



}

void DBWrapper::execQuery(const QString &query)
{
    sqlQueryModel->setQuery(query);

    if (sqlQueryModel->lastError().isValid())
    {
        emit dbError(sqlQueryModel->lastError().text());
    }
}
