#-------------------------------------------------
#
# Project created by QtCreator 2015-07-26T09:42:38
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = DAT
TEMPLATE = app

SOURCES +=  main.cpp\
            gui/MainWindow.cpp \
            lib/DAT.cpp \
            gui/RenameFileDialog.cpp

HEADERS +=  gui/MainWindow.hpp \
            lib/DAT.hpp \
            gui/RenameFileDialog.hpp

FORMS +=    MainWindow.ui \
            RenameFileDialog.ui

