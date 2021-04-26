QT       += core gui
QT       += network

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
    black_ai.cpp \
    black_win_tip.cpp \
    cliant_black.cpp \
    cliant_ready.cpp \
    cliant_white.cpp \
    draw_tip.cpp \
    eve_ai.cpp \
    main.cpp \
    mainwindow.cpp \
    mybackground.cpp \
    myjudgement.cpp \
    myopen.cpp \
    myport_ready.cpp \
    server.cpp \
    server_black.cpp \
    server_ready.cpp \
    server_white.cpp \
    warnin55.cpp \
    warning44.cpp \
    white44_win_tip.cpp \
    white55_win_tip.cpp \
    white_ai.cpp \
    white_win_tip.cpp \
    win_tip.cpp


HEADERS += \
    black_ai.h \
    black_win_tip.h \
    cliant_black.h \
    cliant_ready.h \
    cliant_white.h \
    draw_tip.h \
    eve_ai.h \
    mainwindow.h \
    mybackground.h \ \
    myjudgement.h \
    myopen.h \
    myport_ready.h \
    server.h \
    server_black.h \
    server_ready.h \
    server_white.h \
    warnin55.h \
    warning44.h \
    white44_win_tip.h \
    white55_win_tip.h \
    white_ai.h \
    white_win_tip.h \
    win_tip.h


FORMS += \
    black_ai.ui \
    black_win_tip.ui \
    cliant_black.ui \
    cliant_ready.ui \
    cliant_white.ui \
    draw_tip.ui \
    eve_ai.ui \
    mainwindow.ui \
    myopen.ui \
    myport_ready.ui \
    server.ui \
    server_black.ui \
    server_ready.ui \
    server_white.ui \
    white44_win_tip.ui \
    white55_win_tip.ui \
    white_ai.ui \
    white_win_tip.ui \
    win_tip.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc

DISTFILES += \
