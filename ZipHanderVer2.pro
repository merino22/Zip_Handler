QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QUAZIPCODEDIR = "/home/merino/Aaron/quazip-0.5.1/quazip"
ZLIBCODEDIR = "/home/merino/Aaron/zlib-1.2.11"
unix{
    LIBS += -L$${ZLIBCODEDIR} -lz
}
win32{
    LIBS += -L$${ZLIBCODEDIR} -lzdll
}

INCLUDEPATH += $${QUAZIPCODEDIR}

SOURCES += \
$${QUAZIPCODEDIR}/*.cpp\
$${QUAZIPCODEDIR}/*.c\
    archiveinfodialog.cpp \
    centralDir.cpp \
    dataDescriptor.cpp \
    endCentralDir.cpp \
    localFileHeader.cpp \
    main.cpp \
    pathdialog.cpp \
    readZIP.cpp \
    widget.cpp

HEADERS += \
$${QUAZIPCODEDIR}/*.h\
    FileNode.h \
    archiveinfodialog.h \
    centralDir.h \
    dataDescriptor.h \
    endCentralDir.h \
    localFileHeader.h \
    pathdialog.h \
    readZIP.h \
    widget.h

FORMS += \
    archiveinfodialog.ui \
    pathdialog.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
