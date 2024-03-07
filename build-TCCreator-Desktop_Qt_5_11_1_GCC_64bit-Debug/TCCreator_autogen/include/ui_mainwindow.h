/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QComboBox *testSuite_cb;
    QLabel *label_4;
    QLabel *label;
    QPlainTextEdit *plainTextEdit_3;
    QLineEdit *lineEdit_5;
    QLabel *label_13;
    QLabel *label_6;
    QComboBox *type_cb;
    QPlainTextEdit *plainTextEdit_4;
    QLabel *label_5;
    QComboBox *valid_cb;
    QDateEdit *dateEdit;
    QLabel *label_12;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QLineEdit *testCaseID_line;
    QLabel *label_8;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_10;
    QPushButton *pushButton_2;
    QComboBox *autoAvai_cb;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_11;
    QPlainTextEdit *plainTextEdit_2;
    QLineEdit *author_line;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(454, 775);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setScaledContents(false);

        gridLayout->addWidget(label_9, 15, 0, 1, 2);

        testSuite_cb = new QComboBox(centralwidget);
        testSuite_cb->setObjectName(QStringLiteral("testSuite_cb"));

        gridLayout->addWidget(testSuite_cb, 4, 2, 1, 5);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setScaledContents(false);

        gridLayout->addWidget(label, 1, 0, 1, 2);

        plainTextEdit_3 = new QPlainTextEdit(centralwidget);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));

        gridLayout->addWidget(plainTextEdit_3, 14, 0, 1, 7);

        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 17, 0, 1, 7);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 7, 0, 2, 2);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 9, 0, 1, 2);

        type_cb = new QComboBox(centralwidget);
        type_cb->setObjectName(QStringLiteral("type_cb"));
        type_cb->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(type_cb, 5, 2, 1, 4);

        plainTextEdit_4 = new QPlainTextEdit(centralwidget);
        plainTextEdit_4->setObjectName(QStringLiteral("plainTextEdit_4"));

        gridLayout->addWidget(plainTextEdit_4, 19, 0, 1, 7);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 2);

        valid_cb = new QComboBox(centralwidget);
        valid_cb->setObjectName(QStringLiteral("valid_cb"));

        gridLayout->addWidget(valid_cb, 15, 2, 1, 2);

        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 5, 6, 1, 1);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 18, 0, 1, 2);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 11, 0, 1, 2);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 7, 2, 2, 5);

        testCaseID_line = new QLineEdit(centralwidget);
        testCaseID_line->setObjectName(QStringLiteral("testCaseID_line"));

        gridLayout->addWidget(testCaseID_line, 6, 2, 1, 5);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 13, 0, 1, 2);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 10, 0, 1, 7);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setScaledContents(false);

        gridLayout->addWidget(label_10, 15, 4, 1, 2);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 20, 6, 1, 1);

        autoAvai_cb = new QComboBox(centralwidget);
        autoAvai_cb->setObjectName(QStringLiteral("autoAvai_cb"));

        gridLayout->addWidget(autoAvai_cb, 15, 6, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 20, 4, 1, 2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setScaledContents(false);

        gridLayout->addWidget(label_2, 5, 0, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 16, 0, 1, 2);

        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));

        gridLayout->addWidget(plainTextEdit_2, 12, 0, 1, 7);

        author_line = new QLineEdit(centralwidget);
        author_line->setObjectName(QStringLiteral("author_line"));

        gridLayout->addWidget(author_line, 1, 3, 1, 4);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 454, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Valid TCs:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Testsuite:", nullptr));
        label->setText(QApplication::translate("MainWindow", "Author:", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Functionality:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Test Description:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Test case ID:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Note:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Steps:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Expected Result:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Automation:", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Okay", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Cancel", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Type:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Related Issue:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
