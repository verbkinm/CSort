QT += core gui widgets
CONFIG += c++17

SOURCES += \
    Widgets/Auth/authbanner.cpp \
    Widgets/Auth/authform.cpp \
    Widgets/basicwidget.cpp \
    Widgets/Commands/buttoncommand.cpp \
    Widgets/Commands/commandwidget.cpp \
    Widgets/Monitors/labelmonitor.cpp \
    fabrics.cpp \
    main.cpp \
    mainwindow.cpp \
    Widgets/Monitors/monitorwidget.cpp \
    roles.cpp

HEADERS += \
    Widgets/Monitors/basemonitor.h \
    Widgets/Auth/authbanner.h \
    Widgets/Auth/authform.h \
    Widgets/Commands/basecommand.h \
    Widgets/basicwidget.h \
    Widgets/Commands/buttoncommand.h \
    Widgets/Commands/commandwidget.h \
    Widgets/Monitors/labelmonitor.h \
    fabrics.h \
    mainwindow.h \
    Widgets/Monitors/monitorwidget.h \
    roles.h

FORMS += \
    Widgets/Auth/authbanner.ui \
    Widgets/Auth/authform.ui \
    Widgets/basicwidget.ui \
    mainwindow.ui

INCLUDEPATH += Widgets \
    Widgets/Commands \
    Widgets/Monitors \
    Widgets/Auth

RESOURCES += \
    img.qrc
