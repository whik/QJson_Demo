#-------------------------------------------------
#
# Project created by QtCreator 2019-07-22T18:29:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QJson_Demo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        dialog.cpp \
    parse.cpp \
    create.cpp

HEADERS  += dialog.h \
    json_str.h \
    parse.h \
    create.h

FORMS    += dialog.ui


#QT += printsupport

# qDebug() << tr("Hello World");    支持控制台输出
# CONFIG +=console

RESOURCES += \
    json.qrc
