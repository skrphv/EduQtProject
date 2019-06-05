#ifndef DBWRAPPER_H
#define DBWRAPPER_H

#include <QObject>

class DBWrapper : public QObject
{
    Q_OBJECT
public:
    explicit DBWrapper(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DBWRAPPER_H
