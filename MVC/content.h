#ifndef CONTENT_H
#define CONTENT_H

#include <QtWidgets>

class Content : public QWidget
{
    Q_OBJECT
public:
    explicit Content(QWidget *parent = nullptr);
    ~Content() override = default;

protected:
    QTextEdit*          textEdit              {new QTextEdit                   };
    QListView*          listView              {new QListView                   };
    QSplitter*          hsplitter             {new QSplitter(Qt::Horizontal)   };
    QSplitter*          vsplitter             {new QSplitter(Qt::Vertical  )   };
    QTextEdit*          loggerEdit            {new QTextEdit                   };
    QCheckBox*          checkBoxOneSymbol     {new QCheckBox {"Single Symbol" }};
    QCheckBox*          checkBoxTwoSymbols    {new QCheckBox {"Two Symbols"   }};
    QCheckBox*          checkBoxCaseSensitive {new QCheckBox {"Case Sensetive"}};
    QStandardItemModel* listModel             {new QStandardItemModel          };

    void logMsg (const QString& msg);

private:
    struct ProcessingSettings {
        bool oneSymbol {false};
        bool twoSymbols {false};
        bool caseSensetive {false};
    };

    void processText (const QString& text, const ProcessingSettings& settings);

public slots:
    void processTextFile (const QString& filename);

signals:
    void logMessaging (const QString&);
    void processText();
};

#endif // CONTENT_H
