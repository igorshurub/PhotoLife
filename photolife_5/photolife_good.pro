QT       += core gui
QT       += network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = photolife1
TARGET = app
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database.cpp \
    dialog_login.cpp \
    editing.cpp \
    main.cpp \
    mainwindow.cpp \
    viewing.cpp \

HEADERS += \
    database.h \
    dialog_login.h \
    editing.h \
    mainwindow.h \
    viewing.h \


FORMS += \
    dialog_login.ui \
    editing.ui \
    mainwindow.ui \
    viewing.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resourses.qrc

