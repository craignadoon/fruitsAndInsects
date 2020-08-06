QT += opengl
QT += core \
    gui
# going to hard code clang to c++11
QMAKE_CXX=clang++  -fdiagnostics-fixit-info
DEFINES+=GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
TARGET=FruitAndInsects
DESTDIR=./
OBJECTS_DIR=obj
# this is where we want to put the intermediate build files ( .o)
OBJECTS_DIR=./obj/
MOC_DIR=./moc/

HEADERS += \
    include/MainWindow.h \
    include/basket.h \
    include/fallingChars.h \
    include/gameEntities.h \
    include/gameManager.h \
    include/gameGround.h \
    include/gameWorld.h

SOURCES += \
    src/MainWindow.cpp \
    src/main.cpp \
    src/basket.cpp \
    src/fallingChars.cpp \
    src/gameEntities.cpp \
    src/gameManager.cpp \
    src/gameGround.cpp \
    src/gameWorld.cpp

FORMS += \
    ui/MainWindow.ui

OTHER_FILES += \
    others/Phong.vs \
    others/Phong.fs \
    others/TextureFragment.glsl \
    others/TextureVertex.glsl

CONFIG += console
CONFIG -= app_bundle
DEFINES+=GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED

QMAKE_CXXFLAGS+= -msse -msse2 -msse3
macx:QMAKE_CXXFLAGS+= -arch x86_64
macx:INCLUDEPATH+=/usr/local/boost/
linux-g++:QMAKE_CXXFLAGS +=  -march=native
linux-g++-64:QMAKE_CXXFLAGS +=  -march=native

# define the _DEBUG flag for the graphics lib
DEFINES +=NGL_DEBUG

LIBS += -L/usr/local/lib
# add the ngl lib
LIBS +=  -L/$(HOME)/NGL/lib -l NGL
LIBS += -L/home/sony/glew-1.9.0/lib

# now if we are under unix and not on a Mac (i.e. linux) define GLEW
linux-clang {
    DEFINES += LINUX
    LIBS+= -lGLEW
}
linux-g++-64 {
    DEFINES += LINUX
    LIBS+= -lGLEW
}
DEPENDPATH+=include
# if we are on a mac define DARWIN
macx:DEFINES += DARWIN

# this is where to look for includes
INCLUDEPATH += $$(HOME)/NGL/include/

win32: {
        DEFINES+=USING_GLEW
        INCLUDEPATH+=-I c:/boost_1_44_0
        INCLUDEPATH+=-I c:/boost

        INCLUDEPATH+= -I C:/NGL/Support/glew
        LIBS+= -L C:/NGL/lib
        LIBS+= -lmingw32
        DEFINES += WIN32
        DEFINES += USING_GLEW
        DEFINES +=GLEW_STATIC
        DEFINES+=_WIN32
        SOURCES+=C:/NGL/Support/glew/glew.c
        INCLUDEPATH+=C:/NGL/Support/glew/
}

