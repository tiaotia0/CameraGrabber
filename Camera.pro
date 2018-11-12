#-------------------------------------------------
#
# Project created by QtCreator 2018-10-23T14:51:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Camera
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
        mainwindow.cpp \
    siliconboard.cpp \
    buffertoqimage.cpp \
    cv_calibration.cpp \
    imagedisplaycontroler.cpp \
    GeneratedFiles/Debug/moc_imagecontroler.cpp \
    GeneratedFiles/Debug/moc_imagedisplaycontroler.cpp \
    GeneratedFiles/Debug/moc_mainwindow.cpp \
    GeneratedFiles/Release/moc_imagedisplaycontroler.cpp \
    GeneratedFiles/Release/moc_mainwindow.cpp \
    calibrationdialog.cpp \
    demo.cpp \
    imagecontroler.cpp \
    selectboarddlg.cpp

HEADERS += \
        mainwindow.h \
    siliconboard.h \
    buffertoqimage.h \
    cv_calibration.h \
    imagedisplaycontroler.h \
    debug/moc_predefs.h \
    GeneratedFiles/ui_displaywindow.h \
    GeneratedFiles/ui_mainwindow.h \
    include/clser.h \
    include/fgrab_define.h \
    include/fgrab_prototyp.h \
    include/fgrab_struct.h \
    include/gbe.h \
    include/gbe_error.h \
    include/os_funcs.h \
    include/os_type.h \
    include/siso_auxport.h \
    include/siso_genicam.h \
    include/siso_genicam_error.h \
    include/sisoboards.h \
    include/SisoDisplay.h \
    include/sisoIo.h \
    include/sisoIoBmpErrorCodes.h \
    include/sisoIoFileErrorCodes.h \
    include/sisoIoRawErrorCoedes.h \
    include/sisoIoTiffErrorCodes.h \
    release/moc_predefs.h \
    calibrationdialog.h \
    imagecontroler.h \
    selectboarddlg.h

FORMS += \
        mainwindow.ui \
    calibrationdialog.ui \
    displaywindow.ui

INCLUDEPATH += $$PWD/include


LIBS += -L$$PWD/lib/ -lfglib5
LIBS += -L$$PWD/lib/ -lclsersis

DISTFILES += \
    resources/start.png \
    resources/about.ico \
    resources/close.ico \
    resources/exit.ico \
    resources/init.ico \
    resources/load.ico \
    resources/record.ico \
    resources/save.ico \
    resources/start.ico \
    resources/stop.ico \
    resources/upload.ico

RESOURCES += \
    iconresource.qrc

