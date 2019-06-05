#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout* grid (new QGridLayout(this));

    grid->setMargin(5);
    grid->setSpacing(5);
    grid->addWidget(startBtn, 0, 0);
    grid->addWidget(stopBtn, 0, 1);
    grid->addWidget(logEdit, 1, 0, 2, 2);

    logEdit->setReadOnly(true);
    logEdit->setWordWrapMode(QTextOption::WrapMode::NoWrap);


    connect(startBtn, &QPushButton::clicked, this, &MainWidget::onStart);
    connect(stopBtn , &QPushButton::clicked, this, &MainWidget::onStop );

    connect(server, &QTcpServer::newConnection, this, &MainWidget::onNewConnection);




}

void MainWidget::onStart()
{
    if (server->isListening())
    {
        logMsg("server is already run");
        return;
    }

    if (server->listen(QHostAddress::AnyIPv4, 3227))
    {
        logMsg("server started; port 3227");
    }
    else
    {
        logMsg(server->errorString());
    }

}

void MainWidget::onStop()
{
    server->close();
    logMsg("server closed");
}

void MainWidget::onNewConnection()
{
    logMsg("new connection");

    auto socket = server->nextPendingConnection();

    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    connect(socket, &QTcpSocket::readyRead   , this  , &MainWidget::onReadyRead);

}

void MainWidget::onReadyRead()
{

}

void MainWidget::logMsg(const QString &msg)
{
    auto str = QString("%1    %2")
        .arg(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss"))
        .arg(msg);
    logEdit->append(str);
}
