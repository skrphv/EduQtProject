#include "mainwindow.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , menuBar{new QMenuBar}
    , statusBar {new QStatusBar}
{
    createMenus();
    createStatusBar();

    //auto widget {new QWidget};
    //widget->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    QVBoxLayout* vLayout {new QVBoxLayout(this)};
    vLayout->setMargin(0);
    vLayout->setSpacing(5);
    vLayout->addWidget(menuBar);
    vLayout->addWidget(content);
    vLayout->addWidget(statusBar);

    qDebug() << menuBar->sizePolicy();


    connect(content, &Content::logMessaging, this, [this](const QString& msg){
        statusBar->showMessage(msg, 10000);
    });

    //content(this, &MainWindow::processingText, content, QOverload<>::of(&Content::processText));
}


void MainWindow::createMenus()
{
    QMenu* menuFile {new QMenu("&File", menuBar)};

    menuFile->addAction("&Open", this, [this](){
        auto filename = QFileDialog::getOpenFileName(nullptr,
                                     "Chose text file",
                                     QString(),
                                     "Text files (*.txt);;All files (*.*)");
        if (!filename.isEmpty())
            content->processTextFile (filename);
    },
    Qt::CTRL+Qt::Key_O);

    menuFile->addSeparator();
    menuFile->addAction("E&xit"   , qApp, &QApplication::quit   , Qt::CTRL+Qt::Key_Q );
    menuFile->addAction("About Qt", qApp, &QApplication::aboutQt);


    QMenu* menuEdit {new QMenu("&Edit")};

    menuEdit->addAction("Process Text", this, &MainWindow::processingText, Qt::CTRL+Qt::Key_R);

    menuBar->addMenu(menuFile);
    menuBar->addMenu(menuEdit);
    menuBar->addAction("About Qt", qApp, &QApplication::aboutQt);
}

void MainWindow::createStatusBar()
{

}
