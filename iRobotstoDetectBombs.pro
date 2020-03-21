QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Admin.cpp \
    CustomerService.cpp \
    CustomerTableModel.cpp \
    Database.cpp \
    Help.cpp \
    Pamphlet.cpp \
    Review.cpp \
    Robot.cpp \
    ShoppingCart.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Admin.h \
    Customer.h \
    CustomerService.h \
    CustomerTableModel.h \
    Database.h \
    Help.h \
    Pamphlet.h \
    Review.h \
    Robot.h \
    ShoppingCart.h \
    mainwindow.h

FORMS += \
    Admin.ui \
    CustomerService.ui \
    Help.ui \
    Pamphlet.ui \
    Review.ui \
    Robot.ui \
    ShoppingCart.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    BackgroundPicture.qrc \
    DragonRunner.qrc \
    KingBomb-Omb.qrc \
    TalonRobot.qrc \
    iRobotDetectBomb.qrc
