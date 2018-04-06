#-------------------------------------------------
#
# Project created by QtCreator 2017-02-15T14:28:52
#
#-------------------------------------------------

QT       += core gui
QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = autoupdate2
TEMPLATE = app
QT += xml

SOURCES += main.cpp\
        autoup.cpp \
    downloader.cpp

HEADERS  += autoup.h \
    downloader.h \
    version.h

FORMS    += autoup.ui
