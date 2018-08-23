/********************************************************************************
** Form generated from reading UI file 'RenameFile.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAMEFILE_H
#define UI_RENAMEFILE_H

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

class Ui_RenameFile
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *RenameFile)
    {
        if (RenameFile->objectName().isEmpty())
            RenameFile->setObjectName(QStringLiteral("RenameFile"));
        RenameFile->resize(240, 125);
        buttonBox = new QDialogButtonBox(RenameFile);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 90, 171, 21));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(RenameFile);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 221, 31));
        label->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(RenameFile);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 50, 181, 21));

        retranslateUi(RenameFile);
        QObject::connect(buttonBox, SIGNAL(accepted()), RenameFile, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RenameFile, SLOT(reject()));

        QMetaObject::connectSlotsByName(RenameFile);
    } // setupUi

    void retranslateUi(QDialog *RenameFile)
    {
        RenameFile->setWindowTitle(QApplication::translate("RenameFile", "Dialog", 0));
        label->setText(QApplication::translate("RenameFile", "File name :", 0));
    } // retranslateUi

};

namespace Ui {
    class RenameFile: public Ui_RenameFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAMEFILE_H
