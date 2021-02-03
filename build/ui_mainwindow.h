/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qwebengineview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_File;
    QAction *actionOpen_Dir;
    QAction *actionSelect_Weights;
    QAction *actionReal_TIme;
    QAction *actionStart_Application;
    QAction *actionPause_Application;
    QAction *actionStop;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionReport_Bugs;
    QAction *actionSave;
    QAction *actionSelect_names_file;
    QAction *actionSpeed_Up;
    QAction *actionSpeed_Down;
    QAction *actionScreenshot;
    QAction *actionSimulation;
    QAction *actionSelect_Project_Path;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *GroupBox_Sonar;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_PingNumber;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_SensorHeading;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_SensorPitch;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *label_SensorRoll;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *label_SensorSpeed;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLabel *label_SensorXcoord;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLabel *label_SensorYcoord;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLabel *label_SensorPriAltitude;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLabel *label_ShipGyro;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLabel *label_ShipSpeed;
    QSpacerItem *horizontalSpacer_10;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QLabel *label_TimeStamp;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QLabel *label_SoundVelocity;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_13;
    QLabel *label_SlantRange;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_14;
    QLabel *label_PacketType;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_15;
    QLabel *label_bytePerSample;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_35;
    QLineEdit *lineEdit_Port;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_36;
    QLineEdit *lineEdit_IP;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btn_connect;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btn_start;
    QPushButton *btn_stop;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_view_ping;
    QLabel *label_view_sonar;
    QGroupBox *GroupBox_GeoMap;
    QVBoxLayout *verticalLayout_6;
    QWebEngineView *graphicsView;
    QHBoxLayout *horizontalLayout_22;
    QHBoxLayout *horizontalLayout_20;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_gps;
    QGroupBox *GroupBox_Detection;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter;
    QRadioButton *radioButton_fast;
    QRadioButton *radioButton_precise;
    QRadioButton *radioButton_medium;
    QFrame *line;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_31;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_detectionCounts;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_32;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_detectionBoxesNumber;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_save;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuSelect_Mode;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1700, 1172);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Image/resource/whale.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QStringLiteral("actionOpen_File"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Image/resource/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_File->setIcon(icon1);
        actionOpen_Dir = new QAction(MainWindow);
        actionOpen_Dir->setObjectName(QStringLiteral("actionOpen_Dir"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Image/resource/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Dir->setIcon(icon2);
        actionSelect_Weights = new QAction(MainWindow);
        actionSelect_Weights->setObjectName(QStringLiteral("actionSelect_Weights"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Image/resource/icons8-file-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect_Weights->setIcon(icon3);
        actionReal_TIme = new QAction(MainWindow);
        actionReal_TIme->setObjectName(QStringLiteral("actionReal_TIme"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Image/resource/usb-connected.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReal_TIme->setIcon(icon4);
        actionStart_Application = new QAction(MainWindow);
        actionStart_Application->setObjectName(QStringLiteral("actionStart_Application"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Image/resource/icons8-start-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart_Application->setIcon(icon5);
        actionPause_Application = new QAction(MainWindow);
        actionPause_Application->setObjectName(QStringLiteral("actionPause_Application"));
        actionPause_Application->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Image/resource/pause-squared.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause_Application->setIcon(icon6);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionStop->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Image/resource/icons8-stop-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon7);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Image/resource/close-window.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon8);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Image/resource/icons8-about-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon9);
        actionReport_Bugs = new QAction(MainWindow);
        actionReport_Bugs->setObjectName(QStringLiteral("actionReport_Bugs"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Image/resource/icons8-bug-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReport_Bugs->setIcon(icon10);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Image/resource/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon11);
        actionSelect_names_file = new QAction(MainWindow);
        actionSelect_names_file->setObjectName(QStringLiteral("actionSelect_names_file"));
        actionSelect_names_file->setIcon(icon3);
        actionSpeed_Up = new QAction(MainWindow);
        actionSpeed_Up->setObjectName(QStringLiteral("actionSpeed_Up"));
        actionSpeed_Up->setEnabled(false);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Image/resource/icons8-up-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSpeed_Up->setIcon(icon12);
        actionSpeed_Down = new QAction(MainWindow);
        actionSpeed_Down->setObjectName(QStringLiteral("actionSpeed_Down"));
        actionSpeed_Down->setEnabled(false);
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/Image/resource/icons8-down-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSpeed_Down->setIcon(icon13);
        actionScreenshot = new QAction(MainWindow);
        actionScreenshot->setObjectName(QStringLiteral("actionScreenshot"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/Image/resource/icons8-take-screenshot-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScreenshot->setIcon(icon14);
        actionSimulation = new QAction(MainWindow);
        actionSimulation->setObjectName(QStringLiteral("actionSimulation"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/Image/resource/usb-disconnected.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSimulation->setIcon(icon15);
        actionSelect_Project_Path = new QAction(MainWindow);
        actionSelect_Project_Path->setObjectName(QStringLiteral("actionSelect_Project_Path"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/Image/resource/project-path.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect_Project_Path->setIcon(icon16);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        GroupBox_Sonar = new QGroupBox(centralWidget);
        GroupBox_Sonar->setObjectName(QStringLiteral("GroupBox_Sonar"));
        GroupBox_Sonar->setMaximumSize(QSize(16777215, 200));
        horizontalLayout_17 = new QHBoxLayout(GroupBox_Sonar);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(GroupBox_Sonar);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_PingNumber = new QLabel(GroupBox_Sonar);
        label_PingNumber->setObjectName(QStringLiteral("label_PingNumber"));
        label_PingNumber->setMaximumSize(QSize(16777215, 30));
        label_PingNumber->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_PingNumber->setFrameShape(QFrame::StyledPanel);
        label_PingNumber->setFrameShadow(QFrame::Sunken);
        label_PingNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_PingNumber);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(GroupBox_Sonar);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        label_SensorHeading = new QLabel(GroupBox_Sonar);
        label_SensorHeading->setObjectName(QStringLiteral("label_SensorHeading"));
        label_SensorHeading->setMaximumSize(QSize(16777215, 30));
        label_SensorHeading->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_SensorHeading->setFrameShape(QFrame::StyledPanel);
        label_SensorHeading->setFrameShadow(QFrame::Sunken);
        label_SensorHeading->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_SensorHeading);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(GroupBox_Sonar);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        label_SensorPitch = new QLabel(GroupBox_Sonar);
        label_SensorPitch->setObjectName(QStringLiteral("label_SensorPitch"));
        label_SensorPitch->setMaximumSize(QSize(16777215, 30));
        label_SensorPitch->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_SensorPitch->setFrameShape(QFrame::StyledPanel);
        label_SensorPitch->setFrameShadow(QFrame::Sunken);
        label_SensorPitch->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_SensorPitch);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(GroupBox_Sonar);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        label_SensorRoll = new QLabel(GroupBox_Sonar);
        label_SensorRoll->setObjectName(QStringLiteral("label_SensorRoll"));
        label_SensorRoll->setMaximumSize(QSize(16777215, 30));
        label_SensorRoll->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_SensorRoll->setFrameShape(QFrame::StyledPanel);
        label_SensorRoll->setFrameShadow(QFrame::Sunken);
        label_SensorRoll->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_SensorRoll);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(GroupBox_Sonar);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        label_SensorSpeed = new QLabel(GroupBox_Sonar);
        label_SensorSpeed->setObjectName(QStringLiteral("label_SensorSpeed"));
        label_SensorSpeed->setMaximumSize(QSize(16777215, 30));
        label_SensorSpeed->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_SensorSpeed->setFrameShape(QFrame::StyledPanel);
        label_SensorSpeed->setFrameShadow(QFrame::Sunken);
        label_SensorSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_SensorSpeed);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_16->addLayout(verticalLayout);

        horizontalSpacer_9 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_9);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(GroupBox_Sonar);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        label_SensorXcoord = new QLabel(GroupBox_Sonar);
        label_SensorXcoord->setObjectName(QStringLiteral("label_SensorXcoord"));
        label_SensorXcoord->setMaximumSize(QSize(16777215, 30));
        label_SensorXcoord->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_SensorXcoord->setFrameShape(QFrame::StyledPanel);
        label_SensorXcoord->setFrameShadow(QFrame::Sunken);
        label_SensorXcoord->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_SensorXcoord);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(GroupBox_Sonar);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        label_SensorYcoord = new QLabel(GroupBox_Sonar);
        label_SensorYcoord->setObjectName(QStringLiteral("label_SensorYcoord"));
        label_SensorYcoord->setMaximumSize(QSize(16777215, 30));
        label_SensorYcoord->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_SensorYcoord->setFrameShape(QFrame::StyledPanel);
        label_SensorYcoord->setFrameShadow(QFrame::Sunken);
        label_SensorYcoord->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_SensorYcoord);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(GroupBox_Sonar);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        label_SensorPriAltitude = new QLabel(GroupBox_Sonar);
        label_SensorPriAltitude->setObjectName(QStringLiteral("label_SensorPriAltitude"));
        label_SensorPriAltitude->setMaximumSize(QSize(16777215, 30));
        label_SensorPriAltitude->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_SensorPriAltitude->setFrameShape(QFrame::StyledPanel);
        label_SensorPriAltitude->setFrameShadow(QFrame::Sunken);
        label_SensorPriAltitude->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_SensorPriAltitude);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(GroupBox_Sonar);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_9->addWidget(label_9);

        label_ShipGyro = new QLabel(GroupBox_Sonar);
        label_ShipGyro->setObjectName(QStringLiteral("label_ShipGyro"));
        label_ShipGyro->setMaximumSize(QSize(16777215, 30));
        label_ShipGyro->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_ShipGyro->setFrameShape(QFrame::StyledPanel);
        label_ShipGyro->setFrameShadow(QFrame::Sunken);
        label_ShipGyro->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_ShipGyro);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_10 = new QLabel(GroupBox_Sonar);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_10->addWidget(label_10);

        label_ShipSpeed = new QLabel(GroupBox_Sonar);
        label_ShipSpeed->setObjectName(QStringLiteral("label_ShipSpeed"));
        label_ShipSpeed->setMaximumSize(QSize(16777215, 30));
        label_ShipSpeed->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_ShipSpeed->setFrameShape(QFrame::StyledPanel);
        label_ShipSpeed->setFrameShadow(QFrame::Sunken);
        label_ShipSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(label_ShipSpeed);


        verticalLayout_2->addLayout(horizontalLayout_10);


        horizontalLayout_16->addLayout(verticalLayout_2);

        horizontalSpacer_10 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_10);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_11 = new QLabel(GroupBox_Sonar);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_11->addWidget(label_11);

        label_TimeStamp = new QLabel(GroupBox_Sonar);
        label_TimeStamp->setObjectName(QStringLiteral("label_TimeStamp"));
        label_TimeStamp->setMaximumSize(QSize(16777215, 30));
        label_TimeStamp->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_TimeStamp->setFrameShape(QFrame::StyledPanel);
        label_TimeStamp->setFrameShadow(QFrame::Sunken);
        label_TimeStamp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(label_TimeStamp);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_12 = new QLabel(GroupBox_Sonar);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_12->addWidget(label_12);

        label_SoundVelocity = new QLabel(GroupBox_Sonar);
        label_SoundVelocity->setObjectName(QStringLiteral("label_SoundVelocity"));
        label_SoundVelocity->setMaximumSize(QSize(16777215, 30));
        label_SoundVelocity->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_SoundVelocity->setFrameShape(QFrame::StyledPanel);
        label_SoundVelocity->setFrameShadow(QFrame::Sunken);
        label_SoundVelocity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_12->addWidget(label_SoundVelocity);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_13 = new QLabel(GroupBox_Sonar);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_13->addWidget(label_13);

        label_SlantRange = new QLabel(GroupBox_Sonar);
        label_SlantRange->setObjectName(QStringLiteral("label_SlantRange"));
        label_SlantRange->setMaximumSize(QSize(16777215, 30));
        label_SlantRange->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_SlantRange->setFrameShape(QFrame::StyledPanel);
        label_SlantRange->setFrameShadow(QFrame::Sunken);
        label_SlantRange->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_13->addWidget(label_SlantRange);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_14 = new QLabel(GroupBox_Sonar);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_14->addWidget(label_14);

        label_PacketType = new QLabel(GroupBox_Sonar);
        label_PacketType->setObjectName(QStringLiteral("label_PacketType"));
        label_PacketType->setMaximumSize(QSize(16777215, 30));
        label_PacketType->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_PacketType->setFrameShape(QFrame::StyledPanel);
        label_PacketType->setFrameShadow(QFrame::Sunken);
        label_PacketType->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_14->addWidget(label_PacketType);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_15 = new QLabel(GroupBox_Sonar);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_15->addWidget(label_15);

        label_bytePerSample = new QLabel(GroupBox_Sonar);
        label_bytePerSample->setObjectName(QStringLiteral("label_bytePerSample"));
        label_bytePerSample->setMaximumSize(QSize(16777215, 30));
        label_bytePerSample->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_bytePerSample->setFrameShape(QFrame::StyledPanel);
        label_bytePerSample->setFrameShadow(QFrame::Sunken);
        label_bytePerSample->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_15->addWidget(label_bytePerSample);


        verticalLayout_3->addLayout(horizontalLayout_15);


        horizontalLayout_16->addLayout(verticalLayout_3);


        horizontalLayout_17->addLayout(horizontalLayout_16);


        gridLayout->addWidget(GroupBox_Sonar, 2, 0, 2, 1);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setSizeConstraint(QLayout::SetFixedSize);
        label_35 = new QLabel(centralWidget);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setMinimumSize(QSize(40, 20));

        horizontalLayout_18->addWidget(label_35);

        lineEdit_Port = new QLineEdit(centralWidget);
        lineEdit_Port->setObjectName(QStringLiteral("lineEdit_Port"));
        lineEdit_Port->setMinimumSize(QSize(140, 25));

        horizontalLayout_18->addWidget(lineEdit_Port);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_6);

        label_36 = new QLabel(centralWidget);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setMinimumSize(QSize(75, 20));

        horizontalLayout_18->addWidget(label_36);

        lineEdit_IP = new QLineEdit(centralWidget);
        lineEdit_IP->setObjectName(QStringLiteral("lineEdit_IP"));
        lineEdit_IP->setMinimumSize(QSize(140, 25));

        horizontalLayout_18->addWidget(lineEdit_IP);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_8);

        btn_connect = new QPushButton(centralWidget);
        btn_connect->setObjectName(QStringLiteral("btn_connect"));

        horizontalLayout_18->addWidget(btn_connect);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_7);

        btn_start = new QPushButton(centralWidget);
        btn_start->setObjectName(QStringLiteral("btn_start"));
        btn_start->setMinimumSize(QSize(120, 40));
        btn_start->setMaximumSize(QSize(120, 40));

        horizontalLayout_18->addWidget(btn_start);

        btn_stop = new QPushButton(centralWidget);
        btn_stop->setObjectName(QStringLiteral("btn_stop"));
        btn_stop->setEnabled(false);
        btn_stop->setMinimumSize(QSize(120, 40));
        btn_stop->setMaximumSize(QSize(120, 40));

        horizontalLayout_18->addWidget(btn_stop);


        gridLayout->addLayout(horizontalLayout_18, 3, 1, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_view_ping = new QLabel(centralWidget);
        label_view_ping->setObjectName(QStringLiteral("label_view_ping"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_view_ping->sizePolicy().hasHeightForWidth());
        label_view_ping->setSizePolicy(sizePolicy);
        label_view_ping->setMinimumSize(QSize(0, 80));
        label_view_ping->setMaximumSize(QSize(1024, 80));
        label_view_ping->setMouseTracking(false);
        label_view_ping->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        label_view_ping->setFrameShape(QFrame::StyledPanel);
        label_view_ping->setFrameShadow(QFrame::Plain);
        label_view_ping->setLineWidth(1);
        label_view_ping->setScaledContents(true);

        verticalLayout_5->addWidget(label_view_ping);

        label_view_sonar = new QLabel(centralWidget);
        label_view_sonar->setObjectName(QStringLiteral("label_view_sonar"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_view_sonar->sizePolicy().hasHeightForWidth());
        label_view_sonar->setSizePolicy(sizePolicy1);
        label_view_sonar->setMinimumSize(QSize(0, 800));
        label_view_sonar->setMaximumSize(QSize(1024, 1500));
        label_view_sonar->setMouseTracking(false);
        label_view_sonar->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        label_view_sonar->setFrameShape(QFrame::StyledPanel);
        label_view_sonar->setFrameShadow(QFrame::Plain);
        label_view_sonar->setLineWidth(1);
        label_view_sonar->setScaledContents(true);

        verticalLayout_5->addWidget(label_view_sonar);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 2, 1);

        GroupBox_GeoMap = new QGroupBox(centralWidget);
        GroupBox_GeoMap->setObjectName(QStringLiteral("GroupBox_GeoMap"));
        GroupBox_GeoMap->setMinimumSize(QSize(0, 0));
        GroupBox_GeoMap->setFlat(false);
        verticalLayout_6 = new QVBoxLayout(GroupBox_GeoMap);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        graphicsView = new QWebEngineView(GroupBox_GeoMap);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_6->addWidget(graphicsView);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_11);


        horizontalLayout_22->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        label_gps = new QLabel(GroupBox_GeoMap);
        label_gps->setObjectName(QStringLiteral("label_gps"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_gps->sizePolicy().hasHeightForWidth());
        label_gps->setSizePolicy(sizePolicy2);
        label_gps->setMinimumSize(QSize(0, 0));
        label_gps->setStyleSheet(QStringLiteral(""));
        label_gps->setFrameShape(QFrame::NoFrame);

        horizontalLayout_21->addWidget(label_gps);


        horizontalLayout_22->addLayout(horizontalLayout_21);


        verticalLayout_6->addLayout(horizontalLayout_22);


        gridLayout->addWidget(GroupBox_GeoMap, 1, 1, 2, 1);

        GroupBox_Detection = new QGroupBox(centralWidget);
        GroupBox_Detection->setObjectName(QStringLiteral("GroupBox_Detection"));
        GroupBox_Detection->setMinimumSize(QSize(0, 0));
        GroupBox_Detection->setMaximumSize(QSize(16777215, 400));
        verticalLayout_4 = new QVBoxLayout(GroupBox_Detection);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        splitter = new QSplitter(GroupBox_Detection);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        radioButton_fast = new QRadioButton(splitter);
        radioButton_fast->setObjectName(QStringLiteral("radioButton_fast"));
        splitter->addWidget(radioButton_fast);
        radioButton_precise = new QRadioButton(splitter);
        radioButton_precise->setObjectName(QStringLiteral("radioButton_precise"));
        radioButton_precise->setCheckable(true);
        radioButton_precise->setChecked(false);
        splitter->addWidget(radioButton_precise);
        radioButton_medium = new QRadioButton(splitter);
        radioButton_medium->setObjectName(QStringLiteral("radioButton_medium"));
        splitter->addWidget(radioButton_medium);

        verticalLayout_4->addWidget(splitter);

        line = new QFrame(GroupBox_Detection);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_31 = new QLabel(GroupBox_Detection);
        label_31->setObjectName(QStringLiteral("label_31"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy3);
        label_31->setMinimumSize(QSize(125, 20));

        horizontalLayout_19->addWidget(label_31);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_2);

        label_detectionCounts = new QLabel(GroupBox_Detection);
        label_detectionCounts->setObjectName(QStringLiteral("label_detectionCounts"));
        sizePolicy3.setHeightForWidth(label_detectionCounts->sizePolicy().hasHeightForWidth());
        label_detectionCounts->setSizePolicy(sizePolicy3);
        label_detectionCounts->setMinimumSize(QSize(70, 20));
        label_detectionCounts->setMaximumSize(QSize(16777215, 30));
        label_detectionCounts->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_detectionCounts->setFrameShape(QFrame::StyledPanel);
        label_detectionCounts->setFrameShadow(QFrame::Sunken);
        label_detectionCounts->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_19->addWidget(label_detectionCounts);

        horizontalSpacer_3 = new QSpacerItem(70, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_3);

        label_32 = new QLabel(GroupBox_Detection);
        label_32->setObjectName(QStringLiteral("label_32"));
        sizePolicy3.setHeightForWidth(label_32->sizePolicy().hasHeightForWidth());
        label_32->setSizePolicy(sizePolicy3);
        label_32->setMinimumSize(QSize(170, 20));

        horizontalLayout_19->addWidget(label_32);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_4);

        label_detectionBoxesNumber = new QLabel(GroupBox_Detection);
        label_detectionBoxesNumber->setObjectName(QStringLiteral("label_detectionBoxesNumber"));
        sizePolicy3.setHeightForWidth(label_detectionBoxesNumber->sizePolicy().hasHeightForWidth());
        label_detectionBoxesNumber->setSizePolicy(sizePolicy3);
        label_detectionBoxesNumber->setMinimumSize(QSize(70, 20));
        label_detectionBoxesNumber->setMaximumSize(QSize(16777215, 30));
        label_detectionBoxesNumber->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_detectionBoxesNumber->setFrameShape(QFrame::StyledPanel);
        label_detectionBoxesNumber->setFrameShadow(QFrame::Sunken);
        label_detectionBoxesNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_19->addWidget(label_detectionBoxesNumber);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_5);

        btn_save = new QPushButton(GroupBox_Detection);
        btn_save->setObjectName(QStringLiteral("btn_save"));

        horizontalLayout_19->addWidget(btn_save);


        verticalLayout_4->addLayout(horizontalLayout_19);

        tableWidget = new QTableWidget(GroupBox_Detection);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem7->setFont(font);
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem8->setFont(font);
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_4->addWidget(tableWidget);


        gridLayout->addWidget(GroupBox_Detection, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1700, 22));
        menuBar->setStyleSheet(QStringLiteral("background-color: rgb(211, 215, 207);"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuSelect_Mode = new QMenu(menuEdit);
        menuSelect_Mode->setObjectName(QStringLiteral("menuSelect_Mode"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen_File);
        menuFile->addAction(actionOpen_Dir);
        menuFile->addAction(actionSelect_names_file);
        menuFile->addAction(actionSelect_Weights);
        menuFile->addAction(actionSave);
        menuEdit->addAction(menuSelect_Mode->menuAction());
        menuEdit->addAction(actionSelect_Project_Path);
        menuSelect_Mode->addSeparator();
        menuSelect_Mode->addSeparator();
        menuSelect_Mode->addAction(actionReal_TIme);
        menuSelect_Mode->addAction(actionSimulation);
        menuTools->addAction(actionStart_Application);
        menuTools->addAction(actionPause_Application);
        menuTools->addAction(actionSpeed_Up);
        menuTools->addAction(actionSpeed_Down);
        menuTools->addAction(actionStop);
        menuTools->addAction(actionExit);
        menuTools->addSeparator();
        menuTools->addAction(actionScreenshot);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionReport_Bugs);
        mainToolBar->addAction(actionOpen_File);
        mainToolBar->addAction(actionOpen_Dir);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionSelect_Project_Path);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionStart_Application);
        mainToolBar->addAction(actionStop);
        mainToolBar->addAction(actionPause_Application);
        mainToolBar->addAction(actionExit);
        mainToolBar->addAction(actionSpeed_Up);
        mainToolBar->addAction(actionSpeed_Down);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionReal_TIme);
        mainToolBar->addAction(actionSimulation);
        mainToolBar->addAction(actionScreenshot);

        retranslateUi(MainWindow);

        btn_start->setDefault(true);
        btn_stop->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PCL Ocean Pro V2.0", Q_NULLPTR));
        actionOpen_File->setText(QApplication::translate("MainWindow", "Open File", Q_NULLPTR));
        actionOpen_Dir->setText(QApplication::translate("MainWindow", "Open Dir", Q_NULLPTR));
        actionSelect_Weights->setText(QApplication::translate("MainWindow", "Select Weights", Q_NULLPTR));
        actionReal_TIme->setText(QApplication::translate("MainWindow", "Real-Time", Q_NULLPTR));
        actionStart_Application->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        actionPause_Application->setText(QApplication::translate("MainWindow", "pause", Q_NULLPTR));
        actionStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        actionReport_Bugs->setText(QApplication::translate("MainWindow", "Report Bugs", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save Detetction Info", Q_NULLPTR));
        actionSelect_names_file->setText(QApplication::translate("MainWindow", "Select names file", Q_NULLPTR));
        actionSpeed_Up->setText(QApplication::translate("MainWindow", "Speed Up", Q_NULLPTR));
        actionSpeed_Down->setText(QApplication::translate("MainWindow", "Speed Down", Q_NULLPTR));
        actionScreenshot->setText(QApplication::translate("MainWindow", "Screenshot", Q_NULLPTR));
        actionSimulation->setText(QApplication::translate("MainWindow", "Off-Time", Q_NULLPTR));
        actionSelect_Project_Path->setText(QApplication::translate("MainWindow", "Select Project Path", Q_NULLPTR));
        GroupBox_Sonar->setTitle(QApplication::translate("MainWindow", "Sonar Info", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "PingNumber", Q_NULLPTR));
        label_PingNumber->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "SensorHeading", Q_NULLPTR));
        label_SensorHeading->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "SensorPitch", Q_NULLPTR));
        label_SensorPitch->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "SensorRoll", Q_NULLPTR));
        label_SensorRoll->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "SensorSpeed", Q_NULLPTR));
        label_SensorSpeed->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "SensorXcoord", Q_NULLPTR));
        label_SensorXcoord->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "SensorYcoord", Q_NULLPTR));
        label_SensorYcoord->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "SensorPriAltitude", Q_NULLPTR));
        label_SensorPriAltitude->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "ShipGyro", Q_NULLPTR));
        label_ShipGyro->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "ShipSpeed", Q_NULLPTR));
        label_ShipSpeed->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "TimeStamp", Q_NULLPTR));
        label_TimeStamp->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "SoundVelocity", Q_NULLPTR));
        label_SoundVelocity->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "SlantRange", Q_NULLPTR));
        label_SlantRange->setText(QString());
        label_14->setText(QApplication::translate("MainWindow", "PacketType", Q_NULLPTR));
        label_PacketType->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "bytePerSample", Q_NULLPTR));
        label_bytePerSample->setText(QString());
        label_35->setText(QApplication::translate("MainWindow", "Port ", Q_NULLPTR));
        label_36->setText(QApplication::translate("MainWindow", "IP Address", Q_NULLPTR));
        btn_connect->setText(QApplication::translate("MainWindow", "connect", Q_NULLPTR));
        btn_start->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        btn_stop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        label_view_ping->setText(QString());
        label_view_sonar->setText(QString());
        GroupBox_GeoMap->setTitle(QApplication::translate("MainWindow", "GeoDecoder Map", Q_NULLPTR));
        label_gps->setText(QString());
        GroupBox_Detection->setTitle(QApplication::translate("MainWindow", "Detection Info", Q_NULLPTR));
        radioButton_fast->setText(QApplication::translate("MainWindow", "Fast Detect", Q_NULLPTR));
        radioButton_precise->setText(QApplication::translate("MainWindow", "Precise Detect", Q_NULLPTR));
        radioButton_medium->setText(QApplication::translate("MainWindow", "Medium Detect", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "Detection Counts", Q_NULLPTR));
        label_detectionCounts->setText(QString());
        label_32->setText(QApplication::translate("MainWindow", "Detection Boxes Number", Q_NULLPTR));
        label_detectionBoxesNumber->setText(QString());
        btn_save->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Box Number", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Confidence", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Ping Number", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Port Side", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "NumSample", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Box Width", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Box Height", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Longtitude", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Latitude", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuSelect_Mode->setTitle(QApplication::translate("MainWindow", "Select Mode", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
