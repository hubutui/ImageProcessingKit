#-------------------------------------------------
#
# Project created by QtCreator 2017-10-11T21:38:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ImageProcessingKit
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


SOURCES += \
        main.cpp \
        im.cpp \
    qgraphicssceneplus.cpp \
    dialogadjusthsv.cpp \
    dialoglineartransform.cpp \
    dialogpiecewiselineartransformation.cpp \
    dialogavaragefilter.cpp \
    dialogmedianfilter.cpp \
    dialogmaximumfilter.cpp \
    dialogminimumfilter.cpp \
    dialogcustomfilter.cpp \
    dialogresize.cpp \
    dialogmanualthreshold.cpp \
    dialogerode.cpp \
    dialogregiongrowth.cpp \
    dialogdilate.cpp \
    dialogopening.cpp \
    dialogclosing.cpp \
    dialogidealhighpassfilter.cpp \
    dialogideallowpassfilter.cpp \
    dialogbutterworthlowpassfilter.cpp \
    dialogbutterworthhighpassfilter.cpp \
    dialoghomomorphicfilter.cpp \
    qcustomplot.cpp \
    dialogmotionblur.cpp \
    dialoginversefilter.cpp \
    dialoggaussiannoise.cpp \
    dialogatmosphericcirculation.cpp \
    dialogwienerfilter.cpp \
    dialogifft.cpp

HEADERS += \
        im.h \
    qgraphicssceneplus.h \
    dialogadjusthsv.h \
    dialoglineartransform.h \
    dialogpiecewiselineartransformation.h \
    dialogavaragefilter.h \
    dialogmedianfilter.h \
    dialogmaximumfilter.h \
    dialogminimumfilter.h \
    dialogcustomfilter.h \
    dialogresize.h \
    dialogmanualthreshold.h \
    dialogerode.h \
    dialogregiongrowth.h \
    dialogdilate.h \
    dialogopening.h \
    dialogclosing.h \
    dialogidealhighpassfilter.h \
    dialogideallowpassfilter.h \
    dialogbutterworthlowpassfilter.h \
    dialogbutterworthhighpassfilter.h \
    dialoghomomorphicfilter.h \
    qcustomplot.h \
    dialogmotionblur.h \
    dialoginversefilter.h \
    dialoggaussiannoise.h \
    dialogatmosphericcirculation.h \
    dialogwienerfilter.h \
    dialogifft.h

FORMS += \
        im.ui \
    dialogadjusthsv.ui \
    dialoglineartransform.ui \
    dialogpiecewiselineartransformation.ui \
    dialogavaragefilter.ui \
    dialogmedianfilter.ui \
    dialogmaximumfilter.ui \
    dialogminimumfilter.ui \
    dialogcustomfilter.ui \
    dialogresize.ui \
    dialogmanualthreshold.ui \
    dialogerode.ui \
    dialogregiongrowth.ui \
    dialogdilate.ui \
    dialogopening.ui \
    dialogclosing.ui \
    dialogidealhighpassfilter.ui \
    dialogideallowpassfilter.ui \
    dialogbutterworthlowpassfilter.ui \
    dialogbutterworthhighpassfilter.ui \
    dialoghomomorphicfilter.ui \
    dialogmotionblur.ui \
    dialoginversefilter.ui \
    dialoggaussiannoise.ui \
    dialogatmosphericcirculation.ui \
    dialogwienerfilter.ui \
    dialogifft.ui

unix: LIBS += -lX11
win32: LIBS += -lgdi32
