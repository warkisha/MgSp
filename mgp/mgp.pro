QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
	Crypty/qblowfish.cpp \
	mainDialog/EventLog/eventlog.cpp \
	LogIn/LogIn.cpp \
    main.cpp \
	mainDialog/AddNew/addnew.cpp \
	mainDialog/LookDB/lookbase.cpp \
	mainDialog/dialog.cpp \
	registration/getName.cpp \
	registration/getkey.cpp \
	registration/getpassword.cpp

HEADERS += \
	Crypty/cryData/cryData.h \
	Crypty/crypty.h \
	Crypty/genPsw/genPsw.h \
	Crypty/qblowfish.h \
	Crypty/qblowfish_p.h \
	mainDialog/EventLog/eventlog.h \
	LogIn/LogIn.h \
	DataBase/database.h \
	logging/log.h \
	mainDialog/AddNew/addnew.h \
	mainDialog/LookDB/lookbase.h \
	mainDialog/dialog.h \
	registration/getName.h \
	registration/getkey.h \
	registration/getpassword.h

FORMS += \
	mainDialog/EventLog/eventlog.ui \
	LogIn/LogIn.ui \
	mainDialog/AddNew/addnew.ui \
	mainDialog/LookDB/lookbase.ui \
	mainDialog/dialog.ui \
	registration/getName.ui \
	registration/getkey.ui \
	registration/getpassword.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
