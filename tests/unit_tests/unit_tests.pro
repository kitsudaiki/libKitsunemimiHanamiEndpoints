include(../../defaults.pri)

QT -= qt core gui

CONFIG   -= app_bundle
CONFIG += c++17 console

LIBS += -L../../src -lKitsunemimiHanamiPolicies

LIBS += -L../../../libKitsunemimiCommon/src -lKitsunemimiCommon
LIBS += -L../../../libKitsunemimiCommon/src/debug -lKitsunemimiCommon
LIBS += -L../../../libKitsunemimiCommon/src/release -lKitsunemimiCommon
INCLUDEPATH += ../../../libKitsunemimiCommon/include

INCLUDEPATH += $$PWD

SOURCES += \
    main.cpp  \
    endpoint_test.cpp

HEADERS += \
    endpoint_test.h
