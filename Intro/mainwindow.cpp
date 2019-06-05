#include "mainwindow.h"
#include <QGridLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , btn   {new QPushButton{"Click"}}
    , edit  {new QLineEdit{}}
    , label {new QLabel{"<h1>Label</h1>"}}
{
    QGridLayout* grid {new QGridLayout{}};
    grid->setMargin(5);
    grid->addWidget(label      , 0, 0, 1, 1);
    grid->addWidget(edit       , 0, 1, 1, 1);
    grid->addWidget(new QWidget, 1, 0, 1, 2);
    grid->addWidget(btn        , 2, 0, 1, 2);
    this->setLayout(grid);

    QObject::connect (btn, SIGNAL(clicked()), this, SLOT(setTitleForMainWindow()));
    QObject::connect (btn, &QPushButton::clicked, [this](){
        qDebug() << "Trying lambda...";
        this->createSelf();
    });
    QObject::connect (edit, &QLineEdit::textChanged, [this](const QString& text){
        if (text.toLower() == "one")
            editTextProxy("1");
        else
            editTextProxy(text);
    });
    connect(this, &MainWindow::editTextProxy, this, &MainWindow::setTitleForMainWindow);
    connect(this, &MainWindow::editTextProxy, label, &QLabel::setText);
}

void MainWindow::createSelf()
{
    auto window {new MainWindow {}};

    window->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
    window->show();
}

void MainWindow::setTitleForMainWindow()
{
    this->setWindowTitle (btn->text());
}
