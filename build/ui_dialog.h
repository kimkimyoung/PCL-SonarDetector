/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *GeEncoded;
    QGridLayout *gridLayout_3;
    QLabel *label_geo;
    QWidget *Origin;
    QGridLayout *gridLayout_2;
    QLabel *label_view;
    QWidget *Info;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *Confidence;
    QLabel *PingNumber;
    QLabel *NumberSample;
    QLabel *label;
    QLabel *Longtitude;
    QLabel *Latitude;
    QVBoxLayout *verticalLayout_2;
    QLabel *lable_confidence;
    QLabel *label_pingnumber;
    QLabel *label_numbersample;
    QLabel *label_direction;
    QLabel *label_longtitude;
    QLabel *label_latitude;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        GeEncoded = new QWidget();
        GeEncoded->setObjectName(QStringLiteral("GeEncoded"));
        gridLayout_3 = new QGridLayout(GeEncoded);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_geo = new QLabel(GeEncoded);
        label_geo->setObjectName(QStringLiteral("label_geo"));
        label_geo->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        label_geo->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_geo, 0, 0, 1, 1);

        tabWidget->addTab(GeEncoded, QString());
        Origin = new QWidget();
        Origin->setObjectName(QStringLiteral("Origin"));
        gridLayout_2 = new QGridLayout(Origin);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_view = new QLabel(Origin);
        label_view->setObjectName(QStringLiteral("label_view"));
        label_view->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        label_view->setFrameShape(QFrame::Box);
        label_view->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_view, 0, 0, 1, 1);

        tabWidget->addTab(Origin, QString());
        Info = new QWidget();
        Info->setObjectName(QStringLiteral("Info"));
        horizontalLayout = new QHBoxLayout(Info);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Confidence = new QLabel(Info);
        Confidence->setObjectName(QStringLiteral("Confidence"));

        verticalLayout->addWidget(Confidence);

        PingNumber = new QLabel(Info);
        PingNumber->setObjectName(QStringLiteral("PingNumber"));

        verticalLayout->addWidget(PingNumber);

        NumberSample = new QLabel(Info);
        NumberSample->setObjectName(QStringLiteral("NumberSample"));

        verticalLayout->addWidget(NumberSample);

        label = new QLabel(Info);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        Longtitude = new QLabel(Info);
        Longtitude->setObjectName(QStringLiteral("Longtitude"));

        verticalLayout->addWidget(Longtitude);

        Latitude = new QLabel(Info);
        Latitude->setObjectName(QStringLiteral("Latitude"));

        verticalLayout->addWidget(Latitude);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lable_confidence = new QLabel(Info);
        lable_confidence->setObjectName(QStringLiteral("lable_confidence"));
        lable_confidence->setMinimumSize(QSize(100, 0));

        verticalLayout_2->addWidget(lable_confidence);

        label_pingnumber = new QLabel(Info);
        label_pingnumber->setObjectName(QStringLiteral("label_pingnumber"));
        label_pingnumber->setMinimumSize(QSize(100, 0));

        verticalLayout_2->addWidget(label_pingnumber);

        label_numbersample = new QLabel(Info);
        label_numbersample->setObjectName(QStringLiteral("label_numbersample"));
        label_numbersample->setMinimumSize(QSize(100, 0));

        verticalLayout_2->addWidget(label_numbersample);

        label_direction = new QLabel(Info);
        label_direction->setObjectName(QStringLiteral("label_direction"));
        label_direction->setMinimumSize(QSize(100, 0));

        verticalLayout_2->addWidget(label_direction);

        label_longtitude = new QLabel(Info);
        label_longtitude->setObjectName(QStringLiteral("label_longtitude"));
        label_longtitude->setMinimumSize(QSize(100, 0));

        verticalLayout_2->addWidget(label_longtitude);

        label_latitude = new QLabel(Info);
        label_latitude->setObjectName(QStringLiteral("label_latitude"));
        label_latitude->setMinimumSize(QSize(100, 0));

        verticalLayout_2->addWidget(label_latitude);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tabWidget->addTab(Info, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Target Object", Q_NULLPTR));
        label_geo->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(GeEncoded), QApplication::translate("Dialog", "GeEncoded", Q_NULLPTR));
        label_view->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Origin), QApplication::translate("Dialog", "Origin", Q_NULLPTR));
        Confidence->setText(QApplication::translate("Dialog", "Confidence:", Q_NULLPTR));
        PingNumber->setText(QApplication::translate("Dialog", "Ping Number:", Q_NULLPTR));
        NumberSample->setText(QApplication::translate("Dialog", "Number Sample:", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "Direction:", Q_NULLPTR));
        Longtitude->setText(QApplication::translate("Dialog", "Longtitude:", Q_NULLPTR));
        Latitude->setText(QApplication::translate("Dialog", "Latitude:", Q_NULLPTR));
        lable_confidence->setText(QString());
        label_pingnumber->setText(QString());
        label_numbersample->setText(QString());
        label_direction->setText(QString());
        label_longtitude->setText(QString());
        label_latitude->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Info), QApplication::translate("Dialog", "Info", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
