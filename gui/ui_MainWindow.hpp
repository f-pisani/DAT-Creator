/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionClose;
    QAction *actionNew;
    QAction *actionQuit;
    QWidget *centralWidget;
    QTreeView *treeView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTmp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 440);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(700, 400));
        MainWindow->setMaximumSize(QSize(700, 440));
        MainWindow->setBaseSize(QSize(700, 400));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(700, 400));
        centralWidget->setMaximumSize(QSize(700, 400));
        centralWidget->setBaseSize(QSize(700, 400));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(10, 10, 680, 379));
        treeView->setFrameShape(QFrame::Box);
        treeView->setFrameShadow(QFrame::Sunken);
        treeView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        treeView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeView->setAlternatingRowColors(true);
        treeView->setSelectionMode(QAbstractItemView::MultiSelection);
        treeView->setSelectionBehavior(QAbstractItemView::SelectItems);
        treeView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        treeView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        treeView->setIndentation(10);
        treeView->setUniformRowHeights(true);
        treeView->setItemsExpandable(true);
        treeView->setSortingEnabled(false);
        treeView->setAnimated(true);
        treeView->setAllColumnsShowFocus(true);
        treeView->setHeaderHidden(false);
        treeView->header()->setVisible(true);
        treeView->header()->setCascadingSectionResizes(false);
        treeView->header()->setDefaultSectionSize(100);
        treeView->header()->setHighlightSections(false);
        treeView->header()->setMinimumSectionSize(20);
        treeView->header()->setProperty("showSortIndicator", QVariant(false));
        treeView->header()->setStretchLastSection(false);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuTmp = new QMenu(menuBar);
        menuTmp->setObjectName(QStringLiteral("menuTmp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTmp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DAT Creator", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuTmp->setTitle(QApplication::translate("MainWindow", "tmp", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
