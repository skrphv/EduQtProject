#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

    void createSelf();

protected:
    QPushButton* btn;
    QLineEdit* edit;
    QLabel* label;

signals:
    void editTextProxy(const QString&);

public slots:
    void setTitleForMainWindow();
};
