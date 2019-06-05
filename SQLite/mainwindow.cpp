#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , menuBar (new QMenuBar)
    , statusBar (new QStatusBar)
    , content (new Content)
{
    createMenuBar();
    createStatusBar();

    QVBoxLayout *vLayout {new QVBoxLayout(this)};
    vLayout->setMargin(0);
    vLayout->setSpacing(5);
    vLayout->addWidget(menuBar);
    vLayout->addWidget(content);
    vLayout->addWidget(statusBar);


    connect (this, &MainWindow::openingDatabaseFile,
             content, &Content::onOpeningDBFile);

}

void MainWindow::createStatusBar()
{

}

void MainWindow::createMenuBar()
{
    QMenu* menuFile {new QMenu("File", menuBar)};

    menuFile->addAction("Open", this, &MainWindow::onOpen, Qt::CTRL+Qt::Key_O);
    menuFile->addAction("Run", content, &Content::onRunning);
    menuFile->addSeparator();
    menuFile->addAction("Exit", qApp, &QApplication::quit);



    menuBar->addMenu(menuFile);
}

void MainWindow::onOpen()
{
    const auto fileName =
        QFileDialog::getOpenFileName(this,
                                     "Open DataBase file",
                                     QString(),
                                     "Database files (*.db);;All files (*.*)");

    if (!fileName.isEmpty()) {
        emit openingDatabaseFile(fileName);
    }
}

