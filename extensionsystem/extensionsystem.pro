#-------------------------------------------------
#
# ExtensionSystem pro
#
#-------------------------------------------------
TEMPLATE = lib
TARGET = ExtensionSystem

greaterThan(QT_MAJOR_VERSION, 4): QT += gui widgets

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD
DEFINES += EXTENSIONSYSTEM_LIBRARY

LIBS += -L$$IDE_APP_PATH
unix:!macx:!freebsd*:LIBS += -ldl
DESTDIR = $$IDE_APP_PATH

HEADERS +=  pluginerrorview.h \
            plugindetailsview.h \
            invoker.h \
            iplugin.h \
            iplugin_p.h \
            extensionsystem_global.h \
            pluginmanager.h \
            pluginmanager_p.h \
            pluginspec.h \
            pluginspec_p.h \
            pluginview.h \
            optionsparser.h \
            plugincollection.h \
            pluginerroroverview.h \
            aggregate.h
SOURCES +=  pluginerrorview.cpp \
            plugindetailsview.cpp \
            invoker.cpp \
            iplugin.cpp \
            pluginmanager.cpp \
            pluginspec.cpp \
            pluginview.cpp \
            optionsparser.cpp \
            plugincollection.cpp \
            pluginerroroverview.cpp \
            aggregate.cpp
FORMS +=    pluginerrorview.ui \
            plugindetailsview.ui \
            pluginerroroverview.ui \
            pluginview.ui \

RESOURCES += pluginview.qrc

TRANSLATIONS += translations/ExtensionSystem.zh_CN.ts

target.path = $$PWD/../bin

INSTALLS += target
