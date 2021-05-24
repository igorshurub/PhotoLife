QT += testlib
QT += gui
QT       += core gui
QT       += network
QT       += sql

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_5.cpp \
    database.cpp

HEADERS += \
    database.h
