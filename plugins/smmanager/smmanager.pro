#-------------------------------------------------
#
# Project created by QtCreator 2012-08-01T22:58:16
#
#-------------------------------------------------

OUTPUT_DIR = $$PWD/../..

TARGET = SMManager
TEMPLATE = lib
DEFINES += SMMANAGER_LIBRARY

QT       += core gui widgets

CONFIG   += plugin

HEADERS += \
    smmanagerplugin.h \
    smmanagerview.h

SOURCES += \
    smmanagerplugin.cpp \
    smmanagerview.cpp


OTHER_FILES += \
    smmanager.json

RESOURCES +=

TRANSLATIONS += \
    translations/smmanager.zh_CN.ts


FORMS += \
    smmanagerview.ui

DISTFILES += \
   smmanager.pluginspec

INCLUDEPATH += $$OUTPUT_DIR

LIBS += -L$$OUTPUT_DIR/bin

target_other.files = $$PWD/translations $$PWD/*.pluginspec
target_other.path = $$OUTPUT_DIR/bin/plugins/smmanager
target.path = $$OUTPUT_DIR/bin/plugins/smmanager

INSTALLS += target target_other
