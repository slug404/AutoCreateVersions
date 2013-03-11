#-------------------------------------------------
#
# Project created by QtCreator 2013-02-05T13:41:09
#
#-------------------------------------------------

QT       += core gui
QT += xml
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AutoCreateVersions
TEMPLATE = app


SOURCES += main.cpp\
		WidgetMain.cpp \
	Versions/VersionBase.cpp \
	Versions/VersionCreater.cpp

HEADERS  += WidgetMain.h \
	Versions/VersionBase.h \
	Versions/VersionCreater.h \
	dptr.h \
	Versions/VersionCreater_p.h \
	Versions/VersionBase_p.h

FORMS    += WidgetMain.ui
