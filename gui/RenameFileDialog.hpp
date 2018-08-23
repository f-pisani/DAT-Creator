#ifndef RENAMEFILE_HPP
#define RENAMEFILE_HPP

#include <iostream>

#include <QDialog>

#include "ui_RenameFileDialog.h"

class RenameFileDialog : public QDialog, private Ui::RenameFileDialog
{
    public:
        RenameFileDialog(QWidget* parent=0);
        inline void setFilename(std::string filename){ lineEdit->setText(QString(filename.c_str())); }
        inline std::string getFilename(){ return lineEdit->text().toStdString(); }
};

#endif // RENAMEFILE_HPP
