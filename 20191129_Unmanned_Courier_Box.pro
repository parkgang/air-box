QT       += core gui

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
    client_list.cpp \
    client_login.cpp \
    courier_list.cpp \
    courier_login.cpp \
    insert_box.cpp \
    main.cpp \
    mainwindow.cpp \
    manager_login.cpp \
    manager_menu.cpp \
    payment_window.cpp \
    select_parcel.cpp \
    service_edit.cpp \
    storage_box.cpp

HEADERS += \
    client_list.h \
    client_login.h \
    courier_list.h \
    courier_login.h \
    insert_box.h \
    mainwindow.h \
    manager_login.h \
    manager_menu.h \
    payment_window.h \
    select_parcel.h \
    service_edit.h \
    storage_box.h

FORMS += \
    client_list.ui \
    client_login.ui \
    courier_list.ui \
    courier_login.ui \
    insert_box.ui \
    mainwindow.ui \
    manager_login.ui \
    manager_menu.ui \
    payment_window.ui \
    select_parcel.ui \
    service_edit.ui \
    storage_box.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource/image/image.qrc
