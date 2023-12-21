QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += svg

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    homewindow.cpp \
    main.cpp \
    gui/mainwindow.cpp \
    gui/input_window.cpp \
    gui/keyboard_window.cpp \
    gui/cell.cpp \
    core/game.cpp \

HEADERS += \
    gui/mainwindow.h \
    gui/input_window.h \
    gui/keyboard_window.h \
    gui/cell.h \
    core/game_status.h \
    core/game.h \
    homewindow.h

#FORMS += \
#    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src/logo.qrc \
    src/resource.qrc

FORMS += \
    homewindow.ui
