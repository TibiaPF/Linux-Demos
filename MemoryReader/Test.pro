#-------------------------------------------------
#
# Project created by QtCreator 2016-08-01T00:26:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app


SOURCES += main.cpp\
        testwindow.cpp \
    client.cpp \
    memoryreader.cpp \
    util.cpp

HEADERS  += testwindow.h \
    client.h \
    memoryreader.h \
    util.h

FORMS    += testwindow.ui
