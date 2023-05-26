QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    pointui.cpp

HEADERS += \
    pointui.h

FORMS += \
    pointui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/../yaml-cpp/build/ -lyaml-cpp

INCLUDEPATH += $$PWD/../yaml-cpp/build
DEPENDPATH += $$PWD/../yaml-cpp/build

unix:!macx: PRE_TARGETDEPS += $$PWD/../yaml-cpp/build/libyaml-cpp.a
