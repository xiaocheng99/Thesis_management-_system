#-------------------------------------------------
#
# Project created by QtCreator 2020-05-11T11:52:05
#
#-------------------------------------------------

QT       += core gui
QT   +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sheji
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        logindialog.cpp \
        main.cpp \
        mainwindow.cpp \
        myteadialog.cpp \
        signstudialog.cpp \
        signtechdialog.cpp \
        studialog.cpp \
        stuwindow.cpp \
        teacherdialog.cpp \
        teacherwindow.cpp \
        teastudialog.cpp

HEADERS += \
        logindialog.h \
        mainwindow.h \
        myteadialog.h \
        signstudialog.h \
        signtechdialog.h \
        studialog.h \
        stuwindow.h \
        teacherdialog.h \
        teacherwindow.h \
        teastudialog.h

FORMS += \
        logindialog.ui \
        mainwindow.ui \
        myteadialog.ui \
        signstudialog.ui \
        signtechdialog.ui \
        studialog.ui \
        stuwindow.ui \
        teacherdialog.ui \
        teacherwindow.ui \
        teastudialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
