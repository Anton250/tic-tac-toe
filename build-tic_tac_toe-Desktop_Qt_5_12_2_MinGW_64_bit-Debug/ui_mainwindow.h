/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *Game;
    QPushButton *pushButton_1_1;
    QPushButton *pushButton_1_2;
    QPushButton *pushButton_1_3;
    QPushButton *pushButton_2_1;
    QPushButton *pushButton_2_2;
    QPushButton *pushButton_2_3;
    QPushButton *pushButton_3_1;
    QPushButton *pushButton_3_2;
    QPushButton *pushButton_3_3;
    QLabel *label_textSign;
    QLabel *label_statusOfMove;
    QLabel *label_status;
    QPushButton *pushButton_start;
    QPushButton *pushButton_exit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(819, 523);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Game = new QFrame(centralWidget);
        Game->setObjectName(QString::fromUtf8("Game"));
        Game->setGeometry(QRect(250, 70, 531, 271));
        Game->setFrameShape(QFrame::StyledPanel);
        Game->setFrameShadow(QFrame::Raised);
        pushButton_1_1 = new QPushButton(Game);
        pushButton_1_1->setObjectName(QString::fromUtf8("pushButton_1_1"));
        pushButton_1_1->setGeometry(QRect(0, 0, 91, 91));
        QFont font;
        font.setPointSize(30);
        pushButton_1_1->setFont(font);
        pushButton_1_2 = new QPushButton(Game);
        pushButton_1_2->setObjectName(QString::fromUtf8("pushButton_1_2"));
        pushButton_1_2->setGeometry(QRect(90, 0, 91, 91));
        pushButton_1_2->setFont(font);
        pushButton_1_3 = new QPushButton(Game);
        pushButton_1_3->setObjectName(QString::fromUtf8("pushButton_1_3"));
        pushButton_1_3->setGeometry(QRect(180, 0, 91, 91));
        pushButton_1_3->setFont(font);
        pushButton_2_1 = new QPushButton(Game);
        pushButton_2_1->setObjectName(QString::fromUtf8("pushButton_2_1"));
        pushButton_2_1->setGeometry(QRect(0, 90, 91, 91));
        pushButton_2_1->setFont(font);
        pushButton_2_2 = new QPushButton(Game);
        pushButton_2_2->setObjectName(QString::fromUtf8("pushButton_2_2"));
        pushButton_2_2->setGeometry(QRect(90, 90, 91, 91));
        pushButton_2_2->setFont(font);
        pushButton_2_3 = new QPushButton(Game);
        pushButton_2_3->setObjectName(QString::fromUtf8("pushButton_2_3"));
        pushButton_2_3->setGeometry(QRect(180, 90, 91, 91));
        pushButton_2_3->setFont(font);
        pushButton_3_1 = new QPushButton(Game);
        pushButton_3_1->setObjectName(QString::fromUtf8("pushButton_3_1"));
        pushButton_3_1->setGeometry(QRect(0, 180, 91, 91));
        pushButton_3_1->setFont(font);
        pushButton_3_2 = new QPushButton(Game);
        pushButton_3_2->setObjectName(QString::fromUtf8("pushButton_3_2"));
        pushButton_3_2->setGeometry(QRect(90, 180, 91, 91));
        pushButton_3_2->setFont(font);
        pushButton_3_3 = new QPushButton(Game);
        pushButton_3_3->setObjectName(QString::fromUtf8("pushButton_3_3"));
        pushButton_3_3->setGeometry(QRect(180, 180, 91, 91));
        pushButton_3_3->setFont(font);
        label_textSign = new QLabel(Game);
        label_textSign->setObjectName(QString::fromUtf8("label_textSign"));
        label_textSign->setGeometry(QRect(280, 10, 131, 21));
        QFont font1;
        font1.setPointSize(10);
        label_textSign->setFont(font1);
        label_statusOfMove = new QLabel(Game);
        label_statusOfMove->setObjectName(QString::fromUtf8("label_statusOfMove"));
        label_statusOfMove->setGeometry(QRect(280, 40, 161, 31));
        label_statusOfMove->setFont(font1);
        label_status = new QLabel(centralWidget);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setGeometry(QRect(0, 0, 521, 41));
        QFont font2;
        font2.setPointSize(16);
        label_status->setFont(font2);
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(110, 180, 571, 121));
        QFont font3;
        font3.setPointSize(32);
        pushButton_start->setFont(font3);
        pushButton_exit = new QPushButton(centralWidget);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(720, 0, 93, 28));
        QFont font4;
        font4.setPointSize(12);
        pushButton_exit->setFont(font4);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 819, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_1_1->setText(QString());
        pushButton_1_2->setText(QString());
        pushButton_1_3->setText(QString());
        pushButton_2_1->setText(QString());
        pushButton_2_2->setText(QString());
        pushButton_2_3->setText(QString());
        pushButton_3_1->setText(QString());
        pushButton_3_2->setText(QString());
        pushButton_3_3->setText(QString());
        label_textSign->setText(QApplication::translate("MainWindow", "Your sign is X.", nullptr));
        label_statusOfMove->setText(QApplication::translate("MainWindow", "Your turn.", nullptr));
        label_status->setText(QApplication::translate("MainWindow", "Status", nullptr));
        pushButton_start->setText(QApplication::translate("MainWindow", " Start tne game", nullptr));
        pushButton_exit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
