QT += testlib
QT += gui
QT       += core gui
QT       += network
QT       += sql

CONFIG += qt warn_on depend_includepath testcase

TARGET = tst_database_test
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

SOURCES +=  tst_database_test.cpp \
    database.cpp

HEADERS += \
    database.h
