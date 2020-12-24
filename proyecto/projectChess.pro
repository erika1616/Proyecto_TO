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

SOURCES += \
    bishop.cpp \
    board.cpp \
    choose.cpp \
    eje.cpp \
    horse.cpp \
    king.cpp \
    main.cpp \
    mainwindow.cpp \
    movimientos.cpp \
    pawn.cpp \
    piece.cpp \
    queen.cpp \
    square.cpp \
    tower.cpp \
    winnerdialog.cpp

HEADERS += \
    bishop.h \
    board.h \
    choose.h \
    eje.h \
    horse.h \
    king.h \
    mainwindow.h \
    movimientos.h \
    pawn.h \
    piece.h \
    queen.h \
    square.h \
    tower.h \
    winnerdialog.h

FORMS += \
    choose.ui \
    mainwindow.ui \
    winnerdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    bishop1.png

RESOURCES += \
    imagenes.qrc
