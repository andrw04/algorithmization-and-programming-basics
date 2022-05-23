QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canva.cpp \
    circle.cpp \
    circledialog.cpp \
    ellipse.cpp \
    ellipsedialog.cpp \
    hexagone.cpp \
    hexagonedialog.cpp \
    main.cpp \
    mainwindow.cpp \
    paintscene.cpp \
    rectangle.cpp \
    rectangledialog.cpp \
    shape.cpp \
    square.cpp \
    squaredialog.cpp \
    star.cpp \
    stardialog.cpp \
    triangle.cpp \
    triangledialog.cpp

HEADERS += \
    canva.h \
    circle.h \
    circledialog.h \
    ellipse.h \
    ellipsedialog.h \
    hexagone.h \
    hexagonedialog.h \
    mainwindow.h \
    paintscene.h \
    rectangle.h \
    rectangledialog.h \
    shape.h \
    square.h \
    squaredialog.h \
    star.h \
    stardialog.h \
    triangle.h \
    triangledialog.h

FORMS += \
    canva.ui \
    circledialog.ui \
    ellipsedialog.ui \
    hexagonedialog.ui \
    mainwindow.ui \
    rectangledialog.ui \
    squaredialog.ui \
    stardialog.ui \
    triangledialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
