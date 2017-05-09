#-------------------------------------------------
#
# Project created by QtCreator 2012-08-01T22:58:16
#
#-------------------------------------------------

OUTPUT_DIR = $$PWD/../..

TARGET = BDSChannelOne
TEMPLATE = lib
DEFINES += BDSCHANNELONE_LIBRARY

QT       += core gui widgets

CONFIG   += plugin

HEADERS += \
    bdschanneloneplugin.h \
    bdschanneloneview.h

SOURCES += \
    bdschanneloneplugin.cpp \
    bdschanneloneview.cpp


OTHER_FILES += \
    bdschannelone.json

RESOURCES +=

TRANSLATIONS += \
    translations/bdschannelone.zh_CN.ts


FORMS += \
    bdschanneloneview.ui

DISTFILES += \
    bdschannelone.pluginspec

INCLUDEPATH += $$OUTPUT_DIR

LIBS += -L$$OUTPUT_DIR/bin

target_other.files = $$PWD/translations $$PWD/*.pluginspec
target_other.path = $$OUTPUT_DIR/bin/plugins/bdschannelone
target.path = $$OUTPUT_DIR/bin/plugins/bdschannelone

INSTALLS += target target_other
