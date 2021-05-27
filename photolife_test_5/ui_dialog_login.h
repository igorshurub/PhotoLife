/********************************************************************************
** Form generated from reading UI file 'dialog_login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_LOGIN_H
#define UI_DIALOG_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_login
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_Login;
    QLineEdit *lineEdit_Password;
    QLabel *label_err;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Ok;
    QPushButton *Cancel;

    void setupUi(QDialog *Dialog_login)
    {
        if (Dialog_login->objectName().isEmpty())
            Dialog_login->setObjectName(QString::fromUtf8("Dialog_login"));
        Dialog_login->setEnabled(true);
        Dialog_login->resize(938, 649);
        label = new QLabel(Dialog_login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 210, 221, 51));
        label_2 = new QLabel(Dialog_login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 260, 241, 61));
        label_3 = new QLabel(Dialog_login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 0, 811, 121));
        lineEdit_Login = new QLineEdit(Dialog_login);
        lineEdit_Login->setObjectName(QString::fromUtf8("lineEdit_Login"));
        lineEdit_Login->setGeometry(QRect(430, 220, 241, 31));
        lineEdit_Password = new QLineEdit(Dialog_login);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));
        lineEdit_Password->setGeometry(QRect(430, 280, 241, 31));
        label_err = new QLabel(Dialog_login);
        label_err->setObjectName(QString::fromUtf8("label_err"));
        label_err->setEnabled(true);
        label_err->setGeometry(QRect(380, 120, 231, 61));
        horizontalLayoutWidget = new QWidget(Dialog_login);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(560, 530, 291, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Ok = new QPushButton(horizontalLayoutWidget);
        Ok->setObjectName(QString::fromUtf8("Ok"));
        Ok->setMouseTracking(true);

        horizontalLayout->addWidget(Ok);

        Cancel = new QPushButton(horizontalLayoutWidget);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setMouseTracking(true);

        horizontalLayout->addWidget(Cancel);


        retranslateUi(Dialog_login);

        QMetaObject::connectSlotsByName(Dialog_login);
    } // setupUi

    void retranslateUi(QDialog *Dialog_login)
    {
        Dialog_login->setWindowTitle(QCoreApplication::translate("Dialog_login", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog_login", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#003a55;\">\320\233\320\276\320\263\320\270\320\275:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog_login", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#003a55;\">\320\237\320\260\321\200\320\276\320\273\321\214:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog_login", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600; color:#003a55;\">\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\270\321\200\321\203\320\265\321\202\320\265\321\201\321\214, \320\277\320\276\320\266\320\260\320\273\321\203\320\271\321\201\321\202\320\260!</span></p></body></html>", nullptr));
        label_err->setText(QCoreApplication::translate("Dialog_login", "<html><head/><body><p><span style=\" font-size:14pt; color:#003a55;\">\320\236\321\210\320\270\320\261\320\272\320\260 \320\262 \320\273\320\276\320\263\320\270\320\275\320\265/\320\277\320\260\321\200\320\276\320\273\320\265</span></p></body></html>", nullptr));
        Ok->setText(QCoreApplication::translate("Dialog_login", "Ok", nullptr));
        Cancel->setText(QCoreApplication::translate("Dialog_login", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_login: public Ui_Dialog_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_LOGIN_H

