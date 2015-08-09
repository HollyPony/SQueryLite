#-------------------------------------------------
#
# Project created by QtCreator 2015-08-04T23:48:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SQueryLite
TEMPLATE = app

CONFIG += c++11

SOURCES += \
    src/main.cpp\
    src/mainwindow.cpp \
    src/basedblistmodel.cpp \
    src/propertiesdialog.cpp \
    src/drivers/mongodb.cpp \
    src/drivers/genericdbitem.cpp

HEADERS  += \
    src/mainwindow.h \
    src/basedblistmodel.h \
    src/propertiesdialog.h \
    src/drivers/genericdbitem.h \
    src/drivers/generictable.h \
    src/drivers/genericcolumn.h \
    src/drivers/enumdrivers.h \
    src/drivers/genericserver.h \
    src/drivers/genericdatabase.h \
    src/drivers/mongodb.h

FORMS    += \
    src/mainwindow.ui \
    src/propertiesdialog.ui

macx: LIBS += -L$$PWD/drivers/mongo/lib/ -lmongoclient \
    -L/usr/local/lib \
    -lboost_system-mt \
    -lboost_thread-mt \
    -lboost_regex-mt \
    -lboost_filesystem-mt \
    -lboost_program_options-mt

macx: INCLUDEPATH += /usr/local/include
INCLUDEPATH += $$PWD/drivers/mongo/include
DEPENDPATH += $$PWD/drivers/mongo/include

macx: PRE_TARGETDEPS += $$PWD/drivers/mongo/lib/libmongoclient.a
