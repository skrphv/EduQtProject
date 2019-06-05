#ifndef DBWRAPPER_H
#define DBWRAPPER_H

#include <QtSql>
#include <QtCore>

class DBWrapper : public QObject
{
    Q_OBJECT
public:
    explicit DBWrapper(QObject *parent = nullptr);
    ~DBWrapper() override = default;


    void openDB (const QString& filename);

    QSqlQueryModel* getSqlQueryModel() const {
        return sqlQueryModel;
    }

private:
    QSqlQueryModel *sqlQueryModel;

signals:
    void dbError (const QString&);

public slots:
    void execQuery (const QString& query);
};

#endif // DBWRAPPER_H
