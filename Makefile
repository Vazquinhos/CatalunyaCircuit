#############################################################################
# Makefile for building: Thoth
# Generated by qmake (2.01a) (Qt 4.8.1) on: Tue Apr 9 23:49:13 2013
# Project:  Thoth.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile Thoth.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -fopenmp -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -fopenmp -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4 -I/usr/include/assimp -I/usr/X11R6/include -I. -I.
LINK          = g++
LFLAGS        = -fopenmp
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -L/usr/X11R6/lib -lglut -lGLEW -lGLU -lgomp -lassimp3.0 -lIL -lQtOpenGL -lQtGui -lQtCore -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		Objects/objectmanager.cpp \
		Objects/object3DFile.cpp \
		Objects/enviroment.cpp \
		Objects/car.cpp \
		Objects/absObject3D.cpp \
		Scene/scene.cpp \
		Scene/fragmentview.cpp \
		Utils/vector3D.cpp \
		Utils/point3D.cpp \
		Utils/point2D.cpp \
		Cameras/sphericalcamera.cpp \
		Cameras/freecamera.cpp \
		Cameras/fixedcamera.cpp \
		Cameras/cameramanager.cpp \
		Cameras/cameraabs.cpp \
		Lights/lightmanager.cpp \
		Lights/light.cpp \
		Loaders/settingsexporter.cpp \
		Loaders/lightloader.cpp \
		Loaders/fileParser.cpp \
		Loaders/camerasloader.cpp \
		Ui/lightswindowqt.cpp \
		Ui/importsettingsqt.cpp \
		Ui/exportsettingsqt.cpp \
		Ui/errorwindow.cpp \
		Scene/contextgl.cpp \
		Ui/mainwindow.cpp \
		Ui/camerawindowqt.cpp \
		Ui/carswindowqt.cpp moc_lightswindowqt.cpp \
		moc_importsettingsqt.cpp \
		moc_exportsettingsqt.cpp \
		moc_errorwindow.cpp \
		moc_contextgl.cpp \
		moc_mainwindow.cpp \
		moc_camerawindowqt.cpp \
		moc_carswindowqt.cpp
OBJECTS       = main.o \
		objectmanager.o \
		object3DFile.o \
		enviroment.o \
		car.o \
		absObject3D.o \
		scene.o \
		fragmentview.o \
		vector3D.o \
		point3D.o \
		point2D.o \
		sphericalcamera.o \
		freecamera.o \
		fixedcamera.o \
		cameramanager.o \
		cameraabs.o \
		lightmanager.o \
		light.o \
		settingsexporter.o \
		lightloader.o \
		fileParser.o \
		camerasloader.o \
		lightswindowqt.o \
		importsettingsqt.o \
		exportsettingsqt.o \
		errorwindow.o \
		contextgl.o \
		mainwindow.o \
		camerawindowqt.o \
		carswindowqt.o \
		moc_lightswindowqt.o \
		moc_importsettingsqt.o \
		moc_exportsettingsqt.o \
		moc_errorwindow.o \
		moc_contextgl.o \
		moc_mainwindow.o \
		moc_camerawindowqt.o \
		moc_carswindowqt.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/link_pkgconfig.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Thoth.pro
QMAKE_TARGET  = Thoth
DESTDIR       = 
TARGET        = Thoth

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_lightswindowqt.h ui_importsettingsqt.h ui_exportsettingsqt.h ui_errorwindow.h ui_mainwindow.h ui_camerawindowqt.h ui_carswindowqt.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: Thoth.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/link_pkgconfig.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtOpenGL.prl \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile Thoth.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/link_pkgconfig.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/opengl.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtOpenGL.prl:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile Thoth.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Thoth1.0.0 || $(MKDIR) .tmp/Thoth1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Thoth1.0.0/ && $(COPY_FILE) --parents Objects/objectmanager.h Objects/object3DFile.h Objects/enviroment.h Objects/car.h Objects/absObject3D.h Scene/scene.h Scene/fragmentview.h Utils/vector3D.h Utils/util.h Utils/point3D.h Utils/point2D.h Cameras/sphericalcamera.h Cameras/freecamera.h Cameras/fixedcamera.h Cameras/cameramanager.h Cameras/cameraabs.h Lights/lightmanager.h Lights/light.h Loaders/settingsexporter.h Loaders/lightloader.h Loaders/fileParser.h Loaders/camerasloader.h Ui/lightswindowqt.h Ui/importsettingsqt.h Ui/exportsettingsqt.h Ui/errorwindow.h Scene/contextgl.h Ui/mainwindow.h Ui/camerawindowqt.h Ui/carswindowqt.h .tmp/Thoth1.0.0/ && $(COPY_FILE) --parents main.cpp Objects/objectmanager.cpp Objects/object3DFile.cpp Objects/enviroment.cpp Objects/car.cpp Objects/absObject3D.cpp Scene/scene.cpp Scene/fragmentview.cpp Utils/vector3D.cpp Utils/point3D.cpp Utils/point2D.cpp Cameras/sphericalcamera.cpp Cameras/freecamera.cpp Cameras/fixedcamera.cpp Cameras/cameramanager.cpp Cameras/cameraabs.cpp Lights/lightmanager.cpp Lights/light.cpp Loaders/settingsexporter.cpp Loaders/lightloader.cpp Loaders/fileParser.cpp Loaders/camerasloader.cpp Ui/lightswindowqt.cpp Ui/importsettingsqt.cpp Ui/exportsettingsqt.cpp Ui/errorwindow.cpp Scene/contextgl.cpp Ui/mainwindow.cpp Ui/camerawindowqt.cpp Ui/carswindowqt.cpp .tmp/Thoth1.0.0/ && $(COPY_FILE) --parents Ui/lightswindowqt.ui Ui/importsettingsqt.ui Ui/exportsettingsqt.ui Ui/errorwindow.ui Ui/mainwindow.ui Ui/camerawindowqt.ui Ui/carswindowqt.ui .tmp/Thoth1.0.0/ && (cd `dirname .tmp/Thoth1.0.0` && $(TAR) Thoth1.0.0.tar Thoth1.0.0 && $(COMPRESS) Thoth1.0.0.tar) && $(MOVE) `dirname .tmp/Thoth1.0.0`/Thoth1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Thoth1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_lightswindowqt.cpp moc_importsettingsqt.cpp moc_exportsettingsqt.cpp moc_errorwindow.cpp moc_contextgl.cpp moc_mainwindow.cpp moc_camerawindowqt.cpp moc_carswindowqt.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_lightswindowqt.cpp moc_importsettingsqt.cpp moc_exportsettingsqt.cpp moc_errorwindow.cpp moc_contextgl.cpp moc_mainwindow.cpp moc_camerawindowqt.cpp moc_carswindowqt.cpp
moc_lightswindowqt.cpp: Ui/lightswindowqt.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Ui/lightswindowqt.h -o moc_lightswindowqt.cpp

moc_importsettingsqt.cpp: Ui/importsettingsqt.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Ui/importsettingsqt.h -o moc_importsettingsqt.cpp

moc_exportsettingsqt.cpp: ui_exportsettingsqt.h \
		Loaders/settingsexporter.h \
		Ui/exportsettingsqt.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Ui/exportsettingsqt.h -o moc_exportsettingsqt.cpp

moc_errorwindow.cpp: Ui/errorwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Ui/errorwindow.h -o moc_errorwindow.cpp

moc_contextgl.cpp: Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h \
		Scene/scene.h \
		Objects/objectmanager.h \
		Objects/car.h \
		Objects/object3DFile.h \
		Objects/absObject3D.h \
		Objects/enviroment.h \
		Scene/contextgl.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Scene/contextgl.h -o moc_contextgl.cpp

moc_mainwindow.cpp: Ui/importsettingsqt.h \
		Ui/lightswindowqt.h \
		Ui/exportsettingsqt.h \
		ui_exportsettingsqt.h \
		Loaders/settingsexporter.h \
		Ui/camerawindowqt.h \
		Ui/carswindowqt.h \
		Ui/mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Ui/mainwindow.h -o moc_mainwindow.cpp

moc_camerawindowqt.cpp: Ui/camerawindowqt.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Ui/camerawindowqt.h -o moc_camerawindowqt.cpp

moc_carswindowqt.cpp: Ui/carswindowqt.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Ui/carswindowqt.h -o moc_carswindowqt.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_lightswindowqt.h ui_importsettingsqt.h ui_exportsettingsqt.h ui_errorwindow.h ui_mainwindow.h ui_camerawindowqt.h ui_carswindowqt.h
compiler_uic_clean:
	-$(DEL_FILE) ui_lightswindowqt.h ui_importsettingsqt.h ui_exportsettingsqt.h ui_errorwindow.h ui_mainwindow.h ui_camerawindowqt.h ui_carswindowqt.h
ui_lightswindowqt.h: Ui/lightswindowqt.ui
	/usr/bin/uic-qt4 Ui/lightswindowqt.ui -o ui_lightswindowqt.h

ui_importsettingsqt.h: Ui/importsettingsqt.ui
	/usr/bin/uic-qt4 Ui/importsettingsqt.ui -o ui_importsettingsqt.h

ui_exportsettingsqt.h: Ui/exportsettingsqt.ui
	/usr/bin/uic-qt4 Ui/exportsettingsqt.ui -o ui_exportsettingsqt.h

ui_errorwindow.h: Ui/errorwindow.ui
	/usr/bin/uic-qt4 Ui/errorwindow.ui -o ui_errorwindow.h

ui_mainwindow.h: Ui/mainwindow.ui \
		Scene/contextgl.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h \
		Scene/scene.h \
		Objects/objectmanager.h \
		Objects/car.h \
		Objects/object3DFile.h \
		Objects/absObject3D.h \
		Objects/enviroment.h
	/usr/bin/uic-qt4 Ui/mainwindow.ui -o ui_mainwindow.h

ui_camerawindowqt.h: Ui/camerawindowqt.ui
	/usr/bin/uic-qt4 Ui/camerawindowqt.ui -o ui_camerawindowqt.h

ui_carswindowqt.h: Ui/carswindowqt.ui
	/usr/bin/uic-qt4 Ui/carswindowqt.ui -o ui_carswindowqt.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h \
		Ui/mainwindow.h \
		Ui/importsettingsqt.h \
		Ui/lightswindowqt.h \
		Ui/exportsettingsqt.h \
		ui_exportsettingsqt.h \
		Loaders/settingsexporter.h \
		Ui/camerawindowqt.h \
		Ui/carswindowqt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

objectmanager.o: Objects/objectmanager.cpp Objects/objectmanager.h \
		Objects/car.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h \
		Objects/object3DFile.h \
		Objects/absObject3D.h \
		Objects/enviroment.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objectmanager.o Objects/objectmanager.cpp

object3DFile.o: Objects/object3DFile.cpp Objects/object3DFile.h \
		Objects/absObject3D.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o object3DFile.o Objects/object3DFile.cpp

enviroment.o: Objects/enviroment.cpp Objects/enviroment.h \
		Objects/object3DFile.h \
		Objects/absObject3D.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o enviroment.o Objects/enviroment.cpp

car.o: Objects/car.cpp Objects/car.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h \
		Objects/object3DFile.h \
		Objects/absObject3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o car.o Objects/car.cpp

absObject3D.o: Objects/absObject3D.cpp Objects/absObject3D.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o absObject3D.o Objects/absObject3D.cpp

scene.o: Scene/scene.cpp Scene/scene.h \
		Objects/objectmanager.h \
		Objects/car.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h \
		Objects/object3DFile.h \
		Objects/absObject3D.h \
		Objects/enviroment.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o scene.o Scene/scene.cpp

fragmentview.o: Scene/fragmentview.cpp Scene/fragmentview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fragmentview.o Scene/fragmentview.cpp

vector3D.o: Utils/vector3D.cpp Utils/vector3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o vector3D.o Utils/vector3D.cpp

point3D.o: Utils/point3D.cpp Utils/point3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o point3D.o Utils/point3D.cpp

point2D.o: Utils/point2D.cpp Utils/point2D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o point2D.o Utils/point2D.cpp

sphericalcamera.o: Cameras/sphericalcamera.cpp Cameras/sphericalcamera.h \
		Cameras/cameraabs.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sphericalcamera.o Cameras/sphericalcamera.cpp

freecamera.o: Cameras/freecamera.cpp Cameras/freecamera.h \
		Cameras/cameraabs.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o freecamera.o Cameras/freecamera.cpp

fixedcamera.o: Cameras/fixedcamera.cpp Cameras/fixedcamera.h \
		Cameras/cameraabs.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fixedcamera.o Cameras/fixedcamera.cpp

cameramanager.o: Cameras/cameramanager.cpp Cameras/cameramanager.h \
		Cameras/cameraabs.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cameramanager.o Cameras/cameramanager.cpp

cameraabs.o: Cameras/cameraabs.cpp Cameras/cameraabs.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cameraabs.o Cameras/cameraabs.cpp

lightmanager.o: Lights/lightmanager.cpp Lights/lightmanager.h \
		Lights/light.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o lightmanager.o Lights/lightmanager.cpp

light.o: Lights/light.cpp Lights/light.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o light.o Lights/light.cpp

settingsexporter.o: Loaders/settingsexporter.cpp Loaders/settingsexporter.h \
		Cameras/cameramanager.h \
		Cameras/cameraabs.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h \
		Lights/lightmanager.h \
		Lights/light.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o settingsexporter.o Loaders/settingsexporter.cpp

lightloader.o: Loaders/lightloader.cpp Loaders/lightloader.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o lightloader.o Loaders/lightloader.cpp

fileParser.o: Loaders/fileParser.cpp Loaders/fileParser.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fileParser.o Loaders/fileParser.cpp

camerasloader.o: Loaders/camerasloader.cpp Loaders/camerasloader.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o camerasloader.o Loaders/camerasloader.cpp

lightswindowqt.o: Ui/lightswindowqt.cpp Ui/lightswindowqt.h \
		ui_lightswindowqt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o lightswindowqt.o Ui/lightswindowqt.cpp

importsettingsqt.o: Ui/importsettingsqt.cpp Ui/importsettingsqt.h \
		ui_importsettingsqt.h \
		Ui/errorwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o importsettingsqt.o Ui/importsettingsqt.cpp

exportsettingsqt.o: Ui/exportsettingsqt.cpp Ui/exportsettingsqt.h \
		ui_exportsettingsqt.h \
		Loaders/settingsexporter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o exportsettingsqt.o Ui/exportsettingsqt.cpp

errorwindow.o: Ui/errorwindow.cpp Ui/errorwindow.h \
		ui_errorwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o errorwindow.o Ui/errorwindow.cpp

contextgl.o: Scene/contextgl.cpp Scene/contextgl.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h \
		Scene/scene.h \
		Objects/objectmanager.h \
		Objects/car.h \
		Objects/object3DFile.h \
		Objects/absObject3D.h \
		Objects/enviroment.h \
		Cameras/cameramanager.h \
		Cameras/cameraabs.h \
		Cameras/sphericalcamera.h \
		Cameras/freecamera.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o contextgl.o Scene/contextgl.cpp

mainwindow.o: Ui/mainwindow.cpp Ui/mainwindow.h \
		Ui/importsettingsqt.h \
		Ui/lightswindowqt.h \
		Ui/exportsettingsqt.h \
		ui_exportsettingsqt.h \
		Loaders/settingsexporter.h \
		Ui/camerawindowqt.h \
		Ui/carswindowqt.h \
		ui_mainwindow.h \
		Scene/contextgl.h \
		Utils/util.h \
		Utils/point2D.h \
		Utils/point3D.h \
		Utils/vector3D.h \
		Scene/scene.h \
		Objects/objectmanager.h \
		Objects/car.h \
		Objects/object3DFile.h \
		Objects/absObject3D.h \
		Objects/enviroment.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o Ui/mainwindow.cpp

camerawindowqt.o: Ui/camerawindowqt.cpp Ui/camerawindowqt.h \
		ui_camerawindowqt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o camerawindowqt.o Ui/camerawindowqt.cpp

carswindowqt.o: Ui/carswindowqt.cpp Ui/carswindowqt.h \
		ui_carswindowqt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o carswindowqt.o Ui/carswindowqt.cpp

moc_lightswindowqt.o: moc_lightswindowqt.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_lightswindowqt.o moc_lightswindowqt.cpp

moc_importsettingsqt.o: moc_importsettingsqt.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_importsettingsqt.o moc_importsettingsqt.cpp

moc_exportsettingsqt.o: moc_exportsettingsqt.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_exportsettingsqt.o moc_exportsettingsqt.cpp

moc_errorwindow.o: moc_errorwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_errorwindow.o moc_errorwindow.cpp

moc_contextgl.o: moc_contextgl.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_contextgl.o moc_contextgl.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_camerawindowqt.o: moc_camerawindowqt.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_camerawindowqt.o moc_camerawindowqt.cpp

moc_carswindowqt.o: moc_carswindowqt.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_carswindowqt.o moc_carswindowqt.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

