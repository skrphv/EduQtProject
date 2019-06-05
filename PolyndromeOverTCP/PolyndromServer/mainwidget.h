#pragma once
#include <QtWidgets>
#include <QtNetwork>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget() override = default;

    QPushButton* startBtn = new QPushButton("Start");
    QPushButton* stopBtn = new QPushButton("Stop");
    QTextEdit* logEdit = new QTextEdit;

    QTcpServer* server = new QTcpServer(this);


    void onStart();
    void onStop();

    void onNewConnection();
    void onReadyRead();

    void logMsg (const QString& msg);


};
