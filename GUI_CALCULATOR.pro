#-------------------------------------------------
#
# Project created by QtCreator 2019-05-15T18:32:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI_CALCULATOR
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
        Complex.cpp \
        exp_log.cpp \
        main.cpp \
        mainwindow.cpp \
        Equations.cpp \
        basic_operations.cpp \
        matrix_functions.cpp \
        power_root.cpp \
        trigonometry.cpp

HEADERS += \
        Complexx.h \
        exp_log.h \
        mainwindow.h \
        basic_operations.h \
        equations.h \
        matrix_functions.h \
        power_root.h \
        trigonometry.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    GUI_CALCULATOR.rc \
    Graphics/logo.png \
    icon.ico
RC_FILE = GUI_CALCULATOR.rc
