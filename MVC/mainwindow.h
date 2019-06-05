#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>

#include "content.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    //MainWindow() = default;
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
