#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "content.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

protected:
    QMenuBar* menuBar;
    QStatusBar* statusBar;

    Content* content {new Content {this}};

    void createMenus();
    void createStatusBar();


signals:
    void processingText();
};




#endif // MAINWINDOW_H
