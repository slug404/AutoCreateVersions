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

INCLUDEPATH += ./ \
./Filter \
./Versions

SOURCES += main.cpp\
		WidgetMain.cpp \
	Versions/VersionBase.cpp \
	Versions/VersionCreater.cpp \
	Filter/Filter.cpp \
	Filter/FilterData.cpp \
	Filter/Singleton.cpp

HEADERS  += WidgetMain.h \
	Versions/VersionBase.h \
	Versions/VersionCreater.h \
	dptr.h \
	Versions/VersionCreater_p.h \
	Versions/VersionBase_p.h \
	Filter/Filter.h \
	Filter/FilterData.h \
	Filter/Singleton.h

FORMS    += WidgetMain.ui
