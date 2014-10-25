#-------------------------------------------------
#
# Project created by QtCreator 2014-10-18T14:44:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RobotGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    extApi.c \
    extApiCustom.c \
    extApiPlatform.c

HEADERS  += mainwindow.h \
    extApi.h \
    extApiCustom.h \
    extApiInternal.h \
    extApiPlatform.h

FORMS    += mainwindow.ui
