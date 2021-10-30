include(../../defaults.pri)

QT -= qt core gui

CONFIG   -= app_bundle
CONFIG += c++17 console

LIBS += -L../../src -lKitsunemimiHanamiEndpoints

LIBS += -L../../../libKitsunemimiCommon/src -lKitsunemimiCommon
LIBS += -L../../../libKitsunemimiCommon/src/debug -lKitsunemimiCommon
LIBS += -L../../../libKitsunemimiCommon/src/release -lKitsunemimiCommon
INCLUDEPATH += ../../../libKitsunemimiCommon/include

LIBS += -L../../../libKitsunemimiHanamiCommon/src -lKitsunemimiHanamiCommon
LIBS += -L../../../libKitsunemimiHanamiCommon/src/debug -lKitsunemimiHanamiCommon
LIBS += -L../../../libKitsunemimiHanamiCommon/src/release -lKitsunemimiHanamiCommon
INCLUDEPATH += ../../../libKitsunemimiHanamiCommon/include

INCLUDEPATH += $$PWD

SOURCES += \
    endpoint_test.cpp \
    main.cpp

HEADERS += \
    endpoint_test.h
