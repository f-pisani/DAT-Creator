#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <iostream>
#include <vector>
#include <fstream>

#include <QLocale>
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QCloseEvent>

#include "ui_MainWindow.h"
#include "RenameFileDialog.hpp"

#include "../lib/DAT.hpp"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
    bool closeCurrentDATFile();
    std::string getFilePathByRow(int row);
    std::vector<std::string> getSelectedFilePath();

    DAT m_DAT;
    QString m_DATPath;
    QStandardItemModel* m_treeViewModel;

    public:
        explicit MainWindow(QWidget *parent = 0);

    private slots:
        // Tree view
        void updateTreeViewModel();
        void s_addFile();
        void s_extractSelected();
        void s_renameSelected();
        void s_removeSelected();
        // MenuBar
        void updateMenuBar();
        void on_actionNew_triggered();
        void on_actionLoad_triggered();
        void on_actionSave_triggered();
        void on_actionSave_As_triggered();
        void on_actionClose_triggered();
        void on_actionQuit_triggered();
        void on_actionAbout_triggered();
        // CustomContextMenu
        void on_treeView_customContextMenuRequested(const QPoint &pos);
        // Close event
        void closeEvent(QCloseEvent* e);
        
    signals:
        void DAT_Loaded();
        void DAT_Modified();
        void DAT_Closed();
};

#endif // MAINWINDOW_HPP
