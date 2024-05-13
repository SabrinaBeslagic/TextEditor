#-------------------------------------------------
#
# Project created by QtCreator 2024-05-11T08:56:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = z2Notepad
TEMPLATE = app


SOURCES += main.cpp\
        findword.cpp \
        mainwindow.cpp

HEADERS  += mainwindow.h \
    findword.h

FORMS    += mainwindow.ui \
    findword.ui

RESOURCES += \
    icons.qrc

DISTFILES += \
    Icons/Bold.png \
    Icons/Italic.png \
    Icons/Underline.png
