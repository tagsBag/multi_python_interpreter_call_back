#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <functional>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

#include "strategy/strategy.h"

class Dialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    typedef std::function<double(double)> FunctionEvalCallback;
    typedef std::function<void(std::string)> SetFunctionCallback;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    std::shared_ptr<Strategy> m_strategy;

    Dialog *m_dialog;
    QCPGraph *f_plot;
    QCPGraph *df_plot;

    QAction *actionDialog;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *xi_sbox;
    QLabel *label_2;
    QDoubleSpinBox *xf_sbox;
    QLabel *label_3;
    QDoubleSpinBox *step_sbox;
    QSpacerItem *horizontalSpacer;
    QPushButton *apply_btn;
    QCustomPlot *widget;
    QMenuBar *menubar;
    QMenu *menuView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 583);
        actionDialog = new QAction(MainWindow);
        actionDialog->setObjectName(QString::fromUtf8("actionDialog"));
        actionDialog->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(3, 3, 3, 3);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(label);

        xi_sbox = new QDoubleSpinBox(centralwidget);
        xi_sbox->setObjectName(QString::fromUtf8("xi_sbox"));
        xi_sbox->setMaximumSize(QSize(16777215, 20));
        xi_sbox->setMinimum(-99.000000000000000);
        xi_sbox->setSingleStep(0.500000000000000);

        horizontalLayout->addWidget(xi_sbox);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(label_2);

        xf_sbox = new QDoubleSpinBox(centralwidget);
        xf_sbox->setObjectName(QString::fromUtf8("xf_sbox"));
        xf_sbox->setMaximumSize(QSize(16777215, 20));
        xf_sbox->setMinimum(-99.000000000000000);
        xf_sbox->setSingleStep(0.500000000000000);
        xf_sbox->setValue(1.000000000000000);

        horizontalLayout->addWidget(xf_sbox);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(label_3);

        step_sbox = new QDoubleSpinBox(centralwidget);
        step_sbox->setObjectName(QString::fromUtf8("step_sbox"));
        step_sbox->setMaximumSize(QSize(16777215, 20));
        step_sbox->setMinimum(-99.000000000000000);
        step_sbox->setSingleStep(0.050000000000000);
        step_sbox->setValue(0.050000000000000);

        horizontalLayout->addWidget(step_sbox);

        horizontalSpacer = new QSpacerItem(40, 10, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        apply_btn = new QPushButton(centralwidget);
        apply_btn->setObjectName(QString::fromUtf8("apply_btn"));
        apply_btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(apply_btn);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 500));

        gridLayout->addWidget(widget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 22));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuView->menuAction());
        menuView->addAction(actionDialog);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionDialog->setText(QApplication::translate("MainWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("MainWindow", "xi : ", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "xf : ", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "step :", nullptr));
        apply_btn->setText(QApplication::translate("MainWindow", "apply", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
    } // retranslateUi

};

#endif // MAINWINDOW_H
