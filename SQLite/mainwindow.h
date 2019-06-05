#pragma once

#include <QtWidgets>
#include <content.h>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() override = default;

protected:
    void createStatusBar();
    void createMenuBar();

    void onOpen();

protected:
    QMenuBar* menuBar     {nullptr};
    QStatusBar* statusBar {nullptr};
    Content* content      {nullptr};

signals:
    void openingDatabaseFile(const QString&);
    void runningSignal();
};
