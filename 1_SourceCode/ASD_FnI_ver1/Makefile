#############################################################################
# Makefile for building: FruitAndInsects
# Generated by qmake (2.01a) (Qt 4.8.1) on: Sat Sep 14 13:45:32 2013
# Project:  ASD_FnI.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/unsupported/linux-clang -o Makefile ASD_FnI.pro
#############################################################################

####### Compiler, tools and options

CC            = clang
CXX           = clang++ -fdiagnostics-fixit-info
DEFINES       = -DQT_WEBKIT -DGL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED -DGL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED -DNGL_DEBUG -DLINUX -DQT_NO_DEBUG -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -msse -msse2 -msse3 -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/unsupported/linux-clang -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4 -I/home/navi/NGL/include -I/usr/X11R6/include -Imoc -I.
LINK          = clang++
LFLAGS        = -ccc-gcc-name g++
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -L/usr/X11R6/lib -L/usr/local/lib -L/$(HOME)/NGL/lib -l NGL -L/home/sony/glew-1.9.0/lib -lGLEW -lQtOpenGL -lQtGui -lQtCore -lGL -lpthread 
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

OBJECTS_DIR   = obj/

####### Files

SOURCES       = src/MainWindow.cpp \
		src/main.cpp \
		src/basket.cpp \
		src/fallingChars.cpp \
		src/gameEntities.cpp \
		src/gameManager.cpp \
		src/gameGround.cpp \
		src/gameWorld.cpp moc/moc_MainWindow.cpp \
		moc/moc_gameManager.cpp
OBJECTS       = obj/MainWindow.o \
		obj/main.o \
		obj/basket.o \
		obj/fallingChars.o \
		obj/gameEntities.o \
		obj/gameManager.o \
		obj/gameGround.o \
		obj/gameWorld.o \
		obj/moc_MainWindow.o \
		obj/moc_gameManager.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/clang.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
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
		ASD_FnI.pro
QMAKE_TARGET  = FruitAndInsects
DESTDIR       = 
TARGET        = FruitAndInsects

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

$(TARGET): ui_MainWindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: ASD_FnI.pro  /usr/share/qt4/mkspecs/unsupported/linux-clang/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/clang.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
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
		/usr/lib/x86_64-linux-gnu/libQtOpenGL.prl \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/unsupported/linux-clang -o Makefile ASD_FnI.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/clang.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
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
/usr/lib/x86_64-linux-gnu/libQtOpenGL.prl:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/unsupported/linux-clang -o Makefile ASD_FnI.pro

dist: 
	@$(CHK_DIR_EXISTS) obj/FruitAndInsects1.0.0 || $(MKDIR) obj/FruitAndInsects1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) obj/FruitAndInsects1.0.0/ && $(COPY_FILE) --parents include/MainWindow.h include/basket.h include/fallingChars.h include/gameEntities.h include/gameManager.h include/gameGround.h include/gameWorld.h obj/FruitAndInsects1.0.0/ && $(COPY_FILE) --parents src/MainWindow.cpp src/main.cpp src/basket.cpp src/fallingChars.cpp src/gameEntities.cpp src/gameManager.cpp src/gameGround.cpp src/gameWorld.cpp obj/FruitAndInsects1.0.0/ && $(COPY_FILE) --parents ui/MainWindow.ui obj/FruitAndInsects1.0.0/ && (cd `dirname obj/FruitAndInsects1.0.0` && $(TAR) FruitAndInsects1.0.0.tar FruitAndInsects1.0.0 && $(COMPRESS) FruitAndInsects1.0.0.tar) && $(MOVE) `dirname obj/FruitAndInsects1.0.0`/FruitAndInsects1.0.0.tar.gz . && $(DEL_FILE) -r obj/FruitAndInsects1.0.0


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

compiler_moc_header_make_all: moc/moc_MainWindow.cpp moc/moc_gameManager.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc/moc_MainWindow.cpp moc/moc_gameManager.cpp
moc/moc_MainWindow.cpp: include/gameManager.h \
		include/basket.h \
		include/fallingChars.h \
		include/gameEntities.h \
		include/gameWorld.h \
		include/gameGround.h \
		include/MainWindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) include/MainWindow.h -o moc/moc_MainWindow.cpp

moc/moc_gameManager.cpp: include/basket.h \
		include/fallingChars.h \
		include/gameEntities.h \
		include/gameWorld.h \
		include/gameGround.h \
		include/gameManager.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) include/gameManager.h -o moc/moc_gameManager.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_MainWindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_MainWindow.h
ui_MainWindow.h: ui/MainWindow.ui
	/usr/bin/uic-qt4 ui/MainWindow.ui -o ui_MainWindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

obj/MainWindow.o: src/MainWindow.cpp include/MainWindow.h \
		include/gameManager.h \
		include/basket.h \
		include/fallingChars.h \
		include/gameEntities.h \
		include/gameWorld.h \
		include/gameGround.h \
		ui_MainWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/MainWindow.o src/MainWindow.cpp

obj/main.o: src/main.cpp include/MainWindow.h \
		include/gameManager.h \
		include/basket.h \
		include/fallingChars.h \
		include/gameEntities.h \
		include/gameWorld.h \
		include/gameGround.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/main.o src/main.cpp

obj/basket.o: src/basket.cpp include/basket.h \
		include/fallingChars.h \
		include/gameEntities.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/basket.o src/basket.cpp

obj/fallingChars.o: src/fallingChars.cpp include/fallingChars.h \
		include/gameEntities.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/fallingChars.o src/fallingChars.cpp

obj/gameEntities.o: src/gameEntities.cpp include/gameEntities.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/gameEntities.o src/gameEntities.cpp

obj/gameManager.o: src/gameManager.cpp include/gameManager.h \
		include/basket.h \
		include/fallingChars.h \
		include/gameEntities.h \
		include/gameWorld.h \
		include/gameGround.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/gameManager.o src/gameManager.cpp

obj/gameGround.o: src/gameGround.cpp include/gameGround.h \
		include/gameEntities.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/gameGround.o src/gameGround.cpp

obj/gameWorld.o: src/gameWorld.cpp include/gameWorld.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/gameWorld.o src/gameWorld.cpp

obj/moc_MainWindow.o: moc/moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_MainWindow.o moc/moc_MainWindow.cpp

obj/moc_gameManager.o: moc/moc_gameManager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_gameManager.o moc/moc_gameManager.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

