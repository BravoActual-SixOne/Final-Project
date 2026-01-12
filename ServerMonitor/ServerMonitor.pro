QT += core widgets sql
QT += core widgets network
    CONFIG += c++17
LIBS += -lws2_32
TARGET = ServerMonitor
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    tcpclient.cpp

HEADERS += \
    mainwindow.h \
    tcpclient.h

FORMS += \
    mainwindow.ui
