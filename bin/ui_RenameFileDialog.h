/********************************************************************************
** Form generated from reading UI file 'RenameFileDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAMEFILEDIALOG_H
#define UI_RENAMEFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_RenameFileDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *RenameFileDialog)
    {
        if (RenameFileDialog->objectName().isEmpty())
            RenameFileDialog->setObjectName(QStringLiteral("RenameFileDialog"));
        RenameFileDialog->resize(240, 125);
        buttonBox = new QDialogButtonBox(RenameFileDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 90, 171, 21));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(RenameFileDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 221, 31));
        label->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(RenameFileDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 50, 181, 21));
        lineEdit->setClearButtonEnabled(true);

        retranslateUi(RenameFileDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RenameFileDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RenameFileDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RenameFileDialog);
    } // setupUi

    void retranslateUi(QDialog *RenameFileDialog)
    {
        RenameFileDialog->setWindowTitle(QApplication::translate("RenameFileDialog", "Rename file from DAT", 0));
        label->setText(QApplication::translate("RenameFileDialog", "Current filename:", 0));
    } // retranslateUi

};

namespace Ui {
    class RenameFileDialog: public Ui_RenameFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAMEFILEDIALOG_H
