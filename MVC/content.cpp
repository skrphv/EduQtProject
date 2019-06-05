#include "content.h"
#include <QVBoxLayout>
#include <QTextStream>
#include <QFile>
#include <QDateTime>
#include <QString>
#include <QStringList>
#include <string>

Content::Content(QWidget *parent) : QWidget(parent)
{
    listView->setModel(listModel);

    hsplitter->addWidget(textEdit);
    hsplitter->addWidget(listView);

    hsplitter->setStretchFactor(0, 3);
    hsplitter->setStretchFactor(1, 1);

    vsplitter->addWidget(hsplitter);
    vsplitter->addWidget(loggerEdit);
    vsplitter->setStretchFactor(0, 3);
    vsplitter->setStretchFactor(1, 1);

    auto hLayout { new QHBoxLayout{} };
    hLayout->addWidget(checkBoxOneSymbol);
    hLayout->addWidget(checkBoxTwoSymbols);
    hLayout->addWidget(checkBoxCaseSensitive);
    hLayout->setMargin(5);

    auto vlayout {new QVBoxLayout{this}};
    vlayout->addLayout(hLayout);
    vlayout->addWidget(vsplitter);
    vlayout->setMargin(0);
}

void Content::logMsg(const QString &msg)
{
    loggerEdit->append( QString {"%1  %2"}
                        .arg(QDateTime::currentDateTime().toString())
                        .arg(msg)                                      );

    emit logMessaging(msg);
}

void Content::processText(const QString &text, const ProcessingSettings& settings)
{
    //QString simpleText {text.simplified()};
    QStringList list { text.toLower().split(QRegExp("\\s"), QString::SkipEmptyParts) };

    listModel->clear();

    for (const auto& value : list) {
        QString reverse {};
        reverse.resize(value.size());
        std::copy (value.rbegin(), value.rend(), reverse.begin());
        logMsg( QString{"%1 -> %2"}.arg(value).arg(reverse) );
        if (value == reverse) {
            //listView->addItem(value);
            listModel->appendRow(new QStandardItem(value));
        }
    }

}

void Content::processTextFile (const QString &filename)
{
    QFile textFile {filename};
    if (!textFile.open(QIODevice::ReadOnly)){
        logMsg (textFile.errorString());
        return;
    }
    logMsg (QString {"File %1 is opened!"}.arg(filename));

    QTextStream stream {&textFile};
    QString text {stream.readAll()};
    textEdit->setPlainText(text);

    listModel->clear();

    ProcessingSettings settings {};
    settings.oneSymbol     = checkBoxOneSymbol ->isTristate();
    settings.twoSymbols    = checkBoxTwoSymbols->isTristate();
    settings.caseSensetive = checkBoxOneSymbol ->isTristate();

    processText(text, settings);
}
