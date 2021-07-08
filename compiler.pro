QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += no_keywords

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    binary/lex.yy.c \
    binary/y.tab.c \
    intermediate/AsmVisitor.cpp \
    intermediate/antlr4-runtime/IntermediateBaseVisitor.cpp \
    intermediate/antlr4-runtime/IntermediateLexer.cpp \
    intermediate/antlr4-runtime/IntermediateParser.cpp \
    intermediate/antlr4-runtime/IntermediateVisitor.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    binary/lex.yy.h \
    binary/y.tab.h \
    intermediate/AsmVisitor.h \
    intermediate/antlr4-runtime/IntermediateBaseVisitor.h \
    intermediate/antlr4-runtime/IntermediateLexer.h \
    intermediate/antlr4-runtime/IntermediateParser.h \
    intermediate/antlr4-runtime/IntermediateVisitor.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    intermediate/Intermediate.g4 \
    intermediate/antlr4-runtime/Intermediate.tokens \
    intermediate/antlr4-runtime/IntermediateLexer.tokens

unix:!macx: LIBS += -L/usr/local/lib/ -lantlr4-runtime

INCLUDEPATH += /usr/local/include/antlr4-runtime
DEPENDPATH += /usr/local/include/antlr4-runtime

unix:!macx: PRE_TARGETDEPS += /usr/local/lib/libantlr4-runtime.so
