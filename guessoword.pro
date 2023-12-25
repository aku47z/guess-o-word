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
    rules.cpp \
    statistics.cpp \
    statisticsmanager.cpp


HEADERS += \
    gui/mainwindow.h \
    gui/input_window.h \
    gui/keyboard_window.h \
    gui/cell.h \
    core/game.h \
    homewindow.h \
    rules.h \
    statistics.h \
    statisticsmanager.h


#FORMS += \
#    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src/homeicon.qrc \
    src/leaderboard.qrc \
    src/logo.qrc \
    src/playbotton.qrc \
    src/resource.qrc \
    src/rule.qrc \
    src/rules.qrc \
    src/skull.qrc \
    src/smileface.qrc

FORMS += \
    homewindow.ui \
    rules.ui \
    statistics.ui
