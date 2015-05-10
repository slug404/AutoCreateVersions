#-------------------------------------------------
#
# Project created by QtCreator 2013-02-05T13:41:09
#
#-------------------------------------------------

QT       += core gui
QT += xml
QT += network
CONFIG += c++11

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

win32{
MOC_DIR = _moc
OBJECTS_DIR = _obj
RCC_DIR = _rcc
UI_DIR = _ui
UI_HEADERS_DIR = _ui
UI_SOURCES_DIR = _ui
}else{
MOC_DIR = .moc
OBJECTS_DIR = .obj
RCC_DIR = .rcc
UI_DIR = .ui
UI_HEADERS_DIR = .ui
UI_SOURCES_DIR = .ui
}

