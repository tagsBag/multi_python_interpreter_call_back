#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>

class Dialog : public QDialog
{
    Q_OBJECT

    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *fn_textbox;

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString get_script();
    void set_script(std::string script);

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(630, 335);
        gridLayout_3 = new QGridLayout(Dialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        fn_textbox = new QPlainTextEdit(groupBox);
        fn_textbox->setObjectName(QString::fromUtf8("fn_textbox"));

        gridLayout_2->addWidget(fn_textbox, 1, 0, 1, 1);

        gridLayout_3->addWidget(groupBox, 0, 0, 1, 2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("Dialog", "Script", nullptr));
        label->setText(QApplication::translate("Dialog", "Function :", nullptr));
        label_2->setText(QApplication::translate("Dialog", "Derivative :", nullptr));
    }
};

#endif // DIALOG_H
