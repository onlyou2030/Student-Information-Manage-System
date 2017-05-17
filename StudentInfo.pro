#-------------------------------------------------
#
# Project created by QtCreator 2017-04-22T21:43:06
#
#-------------------------------------------------

QT       += core gui
QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudentInfo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mysql.cpp \
    logging.cpp \
    register.cpp \
    manage.cpp \
    stuinfomanage.cpp \
    addinfo.cpp \
    changestuinfo.cpp

HEADERS  += mainwindow.h \
    mysql.h \
    logging.h \
    register.h \
    manage.h \
    stuinfomanage.h \
    addinfo.h \
    changestuinfo.h

FORMS    += mainwindow.ui \
    logging.ui \
    register.ui \
    manage.ui \
    stuinfomanage.ui \
    addinfo.ui \
    changestuinfo.ui
