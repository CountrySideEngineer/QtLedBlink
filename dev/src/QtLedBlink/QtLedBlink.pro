#-------------------------------------------------
#
# Project created by QtCreator 2018-09-16T20:41:44
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = QtLedBlink
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        qtledblinkmainwindow.cpp \
    model/ciopin.cpp \
    model/cgpiopin.cpp

HEADERS += \
        qtledblinkmainwindow.h \
    model/ciopin.h \
    model/cgpiopin.h

FORMS += \
        qtledblinkmainwindow.ui

unix:{
    INCLUDEPATH += ../libpigpio_wrap/lib \
    INCLUDEPATH += ../libpigpio_wrap/include \

}
win32:{
#    INCLUDEPATH += ../libpigpio_wrap/lib \
    INCLUDEPATH += ../libpigpio_wrap/include \
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#unix:{
#    DEFINES += WINDOW_FULL_SCREEN
#    DEFINES += CALL_PIGPIO_LIBRARY
#    LIBS += -lpthread \
#        -lpigpio_wrap \
#        -lpigpio
#}
linux-rasp-pi-g++:{
    DEFINES += WINDOW_FULL_SCREEN
    DEFINES += USE_PIGPIO_LIBRARY
    LIBS += -lpthread \
        -lpigpio
}

RESOURCES += \
    resources/resource.qrc

DISTFILES +=
