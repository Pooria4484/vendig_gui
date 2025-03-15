QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    productcard.cpp \
    style_library.cpp \
    widgets/backbutton.cpp \
    widgets/keypad.cpp

HEADERS += \
    mainwindow.h \
    productcard.h \
    style_library.h \
    widgets/backbutton.h \
    widgets/keypad.h


FORMS += \
    mainwindow.ui \
    productcard.ui \
    widgets/backbutton.ui \
    widgets/keypad.ui

TRANSLATIONS += \
    vending_fa_IR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
