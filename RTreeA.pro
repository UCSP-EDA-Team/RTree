#-------------------------------------------------
#
# Project created by QtCreator 2015-04-06T18:11:08
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = RTreeA
CONFIG   += console
CONFIG += c++11
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += -lzmq

SOURCES += main.cpp

HEADERS += \
    Tree.h \
    config.h \
    Hyperrectangle.h \
    Connector.h
